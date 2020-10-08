//
//  main.cpp
//  dp[i] = dp[i-1]+dp[i-2]+2(dp[i-3]+dp[i-4]+...)
//  dp[i] = 2*dp[i-1]+dp[i-3]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numTilings(int N) {
        int mod = 1e9 + 7;
        long dp[N + 10];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= N; i++) dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        return dp[N];
    }
};
