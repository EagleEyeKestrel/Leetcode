//
//  main.cpp
//  容易想到用dp[t][i]表示不超过t时间内到达i 花费的最大费用
//  注意t这一维要在前
//  转移方程，dp[t][i]=min(dp[t-w][j]),其中w是和i连边的权值，j是i的所有连边
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        int dp[1024][n];
        vector<pair<int, int>> g[n];
        for (auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = 1e9;
        }
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (int i = 0; i < n; i++) {
                dp[t][i] = dp[t - 1][i];
                for (auto pi: g[i]) {
                    if (pi.second > t) continue;
                    dp[t][i] = min(dp[t][i], dp[t - pi.second][pi.first] + passingFees[i]);
                }
            }
        }
        return dp[maxTime][n - 1] == 1e9 ? -1 : dp[maxTime][n - 1];
    }
};
