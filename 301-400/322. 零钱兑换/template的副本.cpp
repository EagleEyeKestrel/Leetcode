//
//  main.cpp
//  完全背包问题裸题，空间优化到一维
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]])
        int n = coins.size();
        int dp[amount + 1];
        for (int i = 1; i <= amount; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
