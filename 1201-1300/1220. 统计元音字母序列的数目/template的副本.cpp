//
//  main.cpp
//  很简单的dp基础题目...根本称不上困难
//  按照题目中给的状态 一个个对上就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        long dp[n + 1][5];
        for (int j = 0; j < 5; j++) dp[1][j] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        int res = 0;
        for (int j = 0; j < 5; j++) res = (res + dp[n][j]) % mod;
        return res;
    }
};
