//
//  main.cpp
//  完全背包问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int waysToChange(int n) {
        int dp[4][n + 1];
        int coin[4] = {1, 5, 10, 25};
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 4; i++) dp[i][0] = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                if (i) dp[i][j] = dp[i - 1][j];
                if (j >= coin[i]) dp[i][j] = (dp[i][j] + dp[i][j - coin[i]]) % mod;
            }
        }
        return dp[3][n];
    }
};
