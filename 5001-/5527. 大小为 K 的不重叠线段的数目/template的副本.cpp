//
//  main.cpp
//  用dp[n][k]表示0-n-1，放k个线段，其中最后一条的终点要在n-1的个数
//  开始没有最后一条终点的限制条件，这样算空的时候会重复
//  容易得到第一行的dp方程。第一个括号表示最后一条线段长度为1，然后长度为2，3。。
//  如果每次算dp[n][k]的时候计算每一项肯定会超时，所以用个s2数组存一下每次的增量。
//  dp[i][j]比dp[i-1][j]的增量s2是第二行的注释，随着i增加，更新一下s2
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfSets(int n, int k) {
        //dp[n][k] = (dp[0][k-1]+...+dp[n-1][k-1]) + (dp[0][k-1]+...+dp[n-2][k-1] + ...)
        //dp[n][k-1] + dp[n-1][k-1] + ...
        long dp[n + 2][k + 2];
        memset(dp, 0, sizeof(dp));
        long s2[k + 2];
        memset(s2, 0, sizeof(s2));
        dp[2][1] = 1;
        dp[3][1] = 2;
        dp[3][2] = 1;
        s2[0] = 1;
        s2[1] = 3;
        s2[2] = 1;
        for(int i = 4; i <= n; i++) {
            for(int j = 1; j <= min(k, i - 1); j++) {
                dp[i][j] = (dp[i - 1][j] + s2[j - 1]) % mod;
            }
            for(int j = 1; j <= min(k, i - 1); j++) {
                s2[j] = (s2[j] + dp[i][j]) % mod;
            }
        }
        long res = 0;
        for(int i = 1; i <= n; i++) {
            res = (res + dp[i][k]) % mod;
        }
        return res % mod;
    }
};
