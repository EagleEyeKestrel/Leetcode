//
//  main.cpp
//  严格意义上来讲超时的做法，但也能很快通过，应该是数据不是很严
//  用dp[i][j][l]表示前i个数字，cost为j的时候，且最大数字为l的种类数
//  分两种情况。第一种，第i个数字使得搜索代价增加。那么最后一个数字必为l，然后前i-1个数字代价必为j-1，而l可以取从1到l-1的任意数，求和就行
//  第二种情况。第i个数字使得搜索代价没变。说明前面肯定还有l，第i个数字可以从1取到l(注意l也是可以取的)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long mod = 1e9 + 7, res = 0;
        long long dp[n][k + 1][m + 1];
        //dp[i][j][l] = dp[i-1][j-1][1] + ... + dp[i-1][j-1][l-1]
        //dp[i][j][l] = l*dp[i-1][j][l]
        memset(dp, 0, sizeof(dp));
        for (int l = 1; l <= m; l++) dp[0][1][l] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= min(k, i + 1); j++) {
                for (int l = 1; l <= m; l++) {
                    dp[i][j][l] = l * dp[i - 1][j][l] % mod;
                    for (int lastl = 1; lastl < l; lastl++) {
                        dp[i][j][l] += dp[i - 1][j - 1][lastl];
                        dp[i][j][l] %= mod;
                    }
                }
            }
        }
        for (int l = 1; l <= m; l++) res = (res + dp[n - 1][k][l]) % mod;
        return res;
    }
};
