//
//  main.cpp
//  最基础的动态规划问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return *max_element(nums.begin(), nums.end());
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};
