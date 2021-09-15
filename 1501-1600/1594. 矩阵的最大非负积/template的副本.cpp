//
//  main.cpp
//  用mx mn表示到达一个点的最大值/最小值即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mod = 1e9 + 7;
        long long mx[m][n], mn[m][n];
        mx[0][0] = mn[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) mn[i][0] = mx[i][0] = mn[i - 1][0] * grid[i][0];
        for (int j = 1; j < n; j++) mn[0][j] = mx[0][j] = mn[0][j - 1] * grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long v1 = grid[i][j] * mn[i - 1][j];
                long long v2 = grid[i][j] * mn[i][j - 1];
                long long v3 = grid[i][j] * mx[i - 1][j];
                long long v4 = grid[i][j] * mx[i][j - 1];
                mx[i][j] = max(v1, max(v2, max(v3, v4)));
                mn[i][j] = min(v1, min(v2, min(v3, v4)));
            }
        }
        return mx[m - 1][n - 1] >= 0 ? mx[m - 1][n - 1] % mod : -1;
    }
};
