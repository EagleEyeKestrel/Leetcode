//
//  main.cpp
//  这是int65536的代码，用的是更直观的方法
//  dp[l][r]表示，左边取l个，右边取r个的最大分数
//  下一次要么从左边继续取，要么从右边继续取，更新dp[l+1][r]和dp[l][r+1]
//  更直观、简洁的做法
//  Copyright © 2021 int65536. All rights reserved.
//

class Solution
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int n = multipliers.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1e9));
        dp[0][0] = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = 0; l + r < n; ++r) {
                dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + multipliers[l + r] * nums[l]);
                dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + multipliers[l + r] * nums[nums.size() - 1 - r]);
            }
        }
        int ret = -1e9;
        for (int i = 0; i <= n; ++i) {
            ret = max(ret, dp[i][n - i]);
        }
        return ret;
    }
};
