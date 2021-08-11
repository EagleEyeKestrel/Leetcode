//
//  main.cpp
//  最经典的问题，nlogn解决LIS问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), l = 1;
        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[l - 1]) {
                dp[l++] = nums[i];
            } else {
                auto it = lower_bound(dp, dp + l, nums[i]);
                *it = nums[i];
            }
        }
        return l;
    }
};
