//
//  main.cpp
//  和698题几乎完全一模一样
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), s = 0;
        for (int x: matchsticks) s += x;
        if (s % 4) return false;
        int target = s / 4;
        int dp[1 << n];
        for (int i = 0; i < 1 << n; i++) dp[i] = -1;
        dp[0] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                if (dp[mask] + matchsticks[i] > target) continue;
                dp[mask | (1 << i)] = (dp[mask] + matchsticks[i]) % target;
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
