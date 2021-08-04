//
//  main.cpp
//  考虑放最后一对P和D
//  dp[i] = [1 + 2 + ... + (2i-1) dp[i - 1] ]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long dp[n + 10];
        dp[1] = 1;
        dp[2] = 6;
        for (int i = 3; i <= n; i++) {
            dp[i] = i * (2 * i - 1) * dp[i - 1] % mod;
        }
        return dp[n];
    }
};
