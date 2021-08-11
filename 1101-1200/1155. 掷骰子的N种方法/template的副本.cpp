//
//  main.cpp
//  比较简单，dp[i][j]表示前i个骰子扔出j的和有多少种。穷举最后一个骰子扔出k
//  复杂度d2f2
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mod = 1e9 + 7;
        int dp[d + 1][1010];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = i; j <= i * f; j++) {
                for (int k = 1; k <= f; k++) {
                    if (k <= j) dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }
        return dp[d][target];
    }
};
