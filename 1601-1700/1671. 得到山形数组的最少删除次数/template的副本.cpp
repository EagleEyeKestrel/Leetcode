//
//  main.cpp
//  用l[i]表示nums[i]左侧最长上升子序列的长度（包括nums[i]) r[i]同理
//  因为这些可以O(n2)预处理出来，最后也就可以遍历得到了
//  注意一个坑点，就是山顶的两侧必须要有元素！所以有最后的if(l[i] > 1 && r[i] > 1)，比赛的时候WA了一次
//  当然LCS问题可以O(nlogn)解决，所以可以在时间上进一步优化。这里贴的比赛的代码，因为O(n2)肯定可以过，写起来也更加方便
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int l[n], r[n];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        l[0] = 1;
        for(int i = 1; i < n; i++) {
            l[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    l[i] = max(l[i], l[j] + 1);
                }
            }
        }
        r[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            r[i] = 1;
            for(int j = n - 1; j > i; j--) {
                if(nums[i] > nums[j]) {
                    r[i] = max(r[i], r[j] + 1);
                }
            }
        }
        int res = n;
        for(int i = 0; i < n; i++) {
            if(l[i] > 1 && r[i] > 1) {
                res = min(res, n - (l[i] + r[i] - 1));
            }
        }
        return res;
    }
};
