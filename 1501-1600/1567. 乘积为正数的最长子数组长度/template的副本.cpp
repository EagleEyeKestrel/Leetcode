//
//  main.cpp
//  这是一种思路，处理出没有0的每一段数组。显然，如果当前nums[l...i]乘积为正，那么就要寻找之前乘积也为正的最远点。否则，寻找之前乘积为负的最远点
//  另外一种，用pos[i] neg[i]表示以nums[i]结尾的正/负数组最长长度，然后讨论
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(vector<int> &nums, int l, int r) {
        int sign = 1, pos = l - 1, neg = 1e9, res = 0;
        for (int i = l; i <= r; i++) {
            if (nums[i] < 0) sign *= (-1);
            if (sign == 1) {
                res = max(res, i - pos);
            } else {
                res = max(res, i - neg);
                if (neg == 1e9) neg = i;
            }
        }
        return res;
    }
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> v = {-1};
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) v.push_back(i);
        }
        v.push_back(n);
        for (int i = 1; i < v.size(); i++) {
            res = max(res, f(nums, v[i - 1] + 1, v[i] - 1));
        }
        return res;
    }
};
