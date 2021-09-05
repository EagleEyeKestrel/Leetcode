//
//  main.cpp
//  重做了一遍，用dp[i][j]表示前i个点 放k条线段的种类数，发现比原来简洁多了。。
//  用s数组维护dp[0][j]+dp[1][j]+...+dp[i-1][j]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfSets(int n, int k) {
        //dp[i][j]=dp[i-1][j]+(dp[i-1][j-1]+dp[i-2][j-1]+...)
        int mod = 1e9 + 7;
        int dp[n + 1][k + 1], s[k + 1];
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        dp[1][0] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;
        s[0] = 2, s[1] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i - 1); j++) {
                dp[i][j] = (dp[i - 1][j] + s[j - 1]) % mod;
            }
            s[0]++;
            for (int j = 1; j <= min(k, i - 1); j++) {
                s[j] = (s[j] + dp[i][j]) % mod;
            }
        }
        return dp[n][k];
    }
};
