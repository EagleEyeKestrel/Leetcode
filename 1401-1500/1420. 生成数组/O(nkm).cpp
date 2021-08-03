//
//  main.cpp
//  优化。可以发现之前需要对上一次的l进行穷举，求和
//  但实际上，在l逐渐增大的过程中，很多项都是可以复用的
//  所以用s[i][j][l]表示dp[i][j][1] + ... + dp[i][j][l]，进行优化
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long mod = 1e9 + 7, res = 0;
        long long dp[n][k + 1][m + 1], s[n][k + 1][m + 1];
        //dp[i][j][l] = dp[i-1][j-1][1] + ... + dp[i-1][j-1][l-1]
        //dp[i][j][l] = l*dp[i-1][j][l]
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        for (int l = 1; l <= m; l++) dp[0][1][l] = 1, s[0][1][l] = s[0][1][l - 1] + 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= min(k, i + 1); j++) {
                for (int l = 1; l <= m; l++) {
                    dp[i][j][l] = l * dp[i - 1][j][l] % mod;
                    dp[i][j][l] = (dp[i][j][l] + s[i - 1][j - 1][l - 1]) % mod;
                    s[i][j][l] = (s[i][j][l - 1] + dp[i][j][l]) % mod;
                }
            }
        }
        for (int l = 1; l <= m; l++) res = (res + dp[n - 1][k][l]) % mod;
        return res;
    }
};
