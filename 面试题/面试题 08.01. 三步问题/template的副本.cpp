//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int waysToStep(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i >= 2) dp[i] = (dp[i] + dp[i - 2]) % mod;
            if (i >= 3) dp[i] = (dp[i] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};
