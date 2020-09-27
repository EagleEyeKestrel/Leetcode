//
//  main.cpp
//  主要思路，预处理l[i]表示左边前i个元素里，k长度子数组最大和，li标记位置。r同理。
//  然后枚举中间子数组开头位置i，这样就可以找到左右两侧最大子数组的位置，然后更新。
//  没想到一遍写完没犯什么粗心的错误，还行，但还是错了两次
//  一个是，既然是字典序最小，那计算r[i]的时候要用>=
//  另一个，既然r最开始要和r[i + 1]比，那r就得开到n + 2
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int l[n + 1], r[n + 2], li[n + 1], ri[n + 2];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for(int i = k; i <= n; i++) {
            if(s[i] - s[i - k] > l[i - 1]) {
                li[i] = i;
            } else {
                li[i] = li[i - 1];
            }
            l[i] = max(l[i - 1], s[i] - s[i - k]);
        }
        for(int i = n - k + 1; i >= 1; i--) {
            if(s[i + k - 1] - s[i - 1] >= r[i + 1]) {
                ri[i] = i;
            } else {
                ri[i] = ri[i + 1];
            }
            r[i] = max(r[i + 1], s[i + k - 1] - s[i - 1]);
        }
        int resv = 0;
        vector<int> res;
        for(int i = k + 1; i <= n - 2 * k + 1; i++) {
            int nows = l[i - 1] + s[i + k - 1] - s[i - 1] + r[i + k];
            if(nows > resv) {
                resv = nows;
                res = {li[i - 1] - k, i - 1, ri[i + k] - 1};
            }
        }
        return res;
    }
};
