//
//  main.cpp
//  用dp[i][j][k]表示前i个房子，涂成j个街区，其中最后一个颜色为k的最小花费
//  在计算dp[i][j][k]时，只需要穷举i-1的颜色即可
//  复杂度O(m target n2)，刚刚好
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[m][target + 1][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= n; k++) dp[i][j][k] = INT_MAX / 2;
            }
        }
        for (int k = 1; k <= n; k++) {
            if (houses[0] == 0) dp[0][1][k] = cost[0][k - 1];
            if (houses[0] == k) dp[0][1][k] = 0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k <= n; k++) {
                    if (houses[i]) {
                        if (houses[i] != k) continue;
                        for (int lastk = 1; lastk <= n; lastk++) {
                            int lastj = (lastk == k ? j : j - 1);
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][lastj][lastk]);
                        }
                    } else {
                        for (int lastk = 1; lastk <= n; lastk++) {
                            int lastj = (lastk == k ? j : j - 1);
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][lastj][lastk] + cost[i][k - 1]);
                        }
                    }
                }
            }
        }
        int res = INT_MAX / 2;
        for (int k = 1; k <= n; k++) res = min(res, dp[m - 1][target][k]);
        return res == INT_MAX / 2 ? -1 : res;
    }
};
