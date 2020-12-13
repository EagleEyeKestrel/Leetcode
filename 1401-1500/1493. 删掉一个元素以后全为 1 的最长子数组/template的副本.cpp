//
//  main.cpp
//  一种方法，用l[i]表示nums[i]左边连续1的数量，r[i]表示右边。
//  结果就是最大的l[i]+r[i]
//  哦，更好的方法是用滑动窗口，不需要空间
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), tmp = 0, res = 0;
        int l[n], r[n];
        l[0] = 0;
        r[n - 1] = 0;
        for(int i = 0; i < n - 1; i++) {
            if (nums[i]) tmp++;
            else tmp = 0;
            l[i + 1] = tmp;
        }
        tmp = 0;
        for(int i = n - 1; i > 0; i--) {
            if (nums[i]) tmp++;
            else tmp = 0;
            r[i - 1] = tmp;
        }
        for(int i = 0; i < n; i++) {
            res = max(res, l[i] + r[i]);
        }
        return res;
    }
};
