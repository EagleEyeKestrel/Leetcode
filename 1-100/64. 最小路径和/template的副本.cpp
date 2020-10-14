//
//  main.cpp
//  最基础的dp，初始化，dp方程见下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        if(!n || !m) return 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) dp[i][1] = grid[i - 1][0] + dp[i - 1][1];
        for(int j = 1; j <= n; j++) dp[1][j] = grid[0][j - 1] + dp[1][j - 1];
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};
