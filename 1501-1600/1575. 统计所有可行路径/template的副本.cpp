//
//  main.cpp
//  比较容易的dp，用dp[k][j]表示到达j 还有k的燃料的状态方案数
//  直接穷举是从i到达j，增加方案
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int mod = 1e9 + 7, n = locations.size(), res = 0;
        int dp[fuel + 1][n];
        memset(dp, 0, sizeof(dp));
        dp[fuel][start] = 1;
        for (int k = fuel - 1; k >= 0; k--) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (i == j) continue;
                    int x = abs(locations[i] - locations[j]);
                    if (k + x > fuel) continue;
                    dp[k][j] = (dp[k][j] + dp[k + x][i]) % mod;
                }
            }
        }
        for (int k = 0; k <= fuel; k++) res = (res + dp[k][finish]) % mod;
        return res;
    }
};
