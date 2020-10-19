//
//  main.cpp
//  很不错的一道题。容易看出递推方程是注释的第一行
//  就这样暴力似乎也可以过，但本题是有O(nk)的解法
//  遇到累加和的形式，考虑能不能转化成几项的和/差
//  另外，还要注意对j>=i的讨论，以及mod之后要保持非负
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9 + 7;
        //dp[n][k] = dp[n-1][k] + dp[n-1][k-1]+...+dp[n-1][k-(n-1)] 或 dp[n-1][0]
        //dp[n][k-1] = dp[n-1][k-1] + ... + dp[n-1][k-n]
        //dp[n][k-1] - dp[n-1][k-n] = dp[n-1][k-1] + ... +dp[n-1][k-(n-1)]
        //所以dp[n][k] = dp[n][k-1] - dp[n-1][k-n] + dp[n-1][k]
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 2; i <= n; i++) {
            int tmp = 1;
            for(int j = 1; j <= k; j++) {
                if(j >= i) dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i]) % mod + mod) % mod;
                else {
                    tmp = (tmp + dp[i - 1][j]) % mod;
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[n][k];
    }
};
