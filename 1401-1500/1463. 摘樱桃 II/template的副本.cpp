//
//  main.cpp
//  不难，用dp[i][j][k]表示第i行，两个人分别走在第j k列时的最大分数
//  对于dp[i][j][k],上一个状态最多有九种。穷举即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        int dp[m][n][n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == 0 && k == n - 1) dp[0][j][k] = grid[0][0] + grid[0][n - 1];
                else dp[0][j][k] = -1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int j1 = j + d1, k1 = k + d2;
                            if (j1 < 0 || j1 >= n || k1 < 0 || k1 >= n || dp[i - 1][j1][k1] == -1) continue;
                            int tmp;
                            if (j == k) tmp = grid[i][j] + dp[i - 1][j1][k1];
                            else tmp = grid[i][j] + grid[i][k] + dp[i - 1][j1][k1];
                            dp[i][j][k] = max(dp[i][j][k], tmp);
                        }
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res = max(res, dp[m - 1][j][k]);
            }
        }
        return res;
    }
};
