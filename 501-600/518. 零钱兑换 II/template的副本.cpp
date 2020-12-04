//
//  main.cpp
//  用dp[i][j]表示前i个硬币组成j元，有多少种
//  考虑组成j元的序列最大的硬币。如果你拿coins[i]，那么要组成剩余的j-coins[i]，还有dp[i][j-coins[i]]种
//  如果不拿，那么剩余所有的硬币都从前i-1个里面取，就是dp[i-1][j]种
//  dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
//  优化成一维
//  dp[j] = dp[j] + dp[j - coins[i]]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
