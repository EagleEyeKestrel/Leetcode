//
//  main.cpp
//  比较简单的dp，用dp[i]表示当前步走到i的种类数
//  就是数组开多大比较难说，这里就开了steps+10，因为最多往前一直走steps步
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9 + 7;
        long dp[steps + 10];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            long tmp[steps + 10];
            for (int i = 0; i < steps + 10; i++) {
                if (i == 0) {
                    tmp[i] = (dp[i]) % mod;
                    if (arrLen > 1) tmp[i] = (tmp[i] + dp[i + 1]) % mod;
                } else if (i == steps + 9) {
                    tmp[i] = (dp[i] + dp[i - 1]) % mod;
                } else {
                    tmp[i] = (dp[i] + dp[i - 1]) % mod;
                    if (i < arrLen - 1) tmp[i] = (tmp[i] + dp[i + 1]) % mod;
                }
            }
            memcpy(dp, tmp, sizeof(tmp));
        }
        return dp[0];
    }
};
