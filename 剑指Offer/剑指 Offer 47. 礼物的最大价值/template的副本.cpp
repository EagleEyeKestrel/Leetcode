//
//  main.cpp
//  最基础的dp
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
