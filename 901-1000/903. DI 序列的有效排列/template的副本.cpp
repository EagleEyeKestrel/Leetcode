//
//  main.cpp
//  用dp[i][j]表示前i+1个数，并且在第i+1个数之后还有j个更小的数 有多少种
//  根据上一位是D还是S进行更新
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int numPermsDISequence(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        //s[i-1]=='D' dp[i][j]=dp[i-1][j+1]+dp[i-1][j+2]+...+dp[i-1][n+1-i]
        //s[i-1]=='I' dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][0]
        //j in [0, n-i]
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                dp[i][j] = 0;
                if (s[i - 1] == 'D') {
                    for (int k = j + 1; k <= n + 1 - i; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                } else {
                    for (int k = 0; k <= j; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        }
        return dp[n][0];
    }
};
