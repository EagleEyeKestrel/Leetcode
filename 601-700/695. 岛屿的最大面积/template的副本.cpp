//
//  main.cpp
//  dfs的基础题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[60][60];
    int direx[4] = {-1, 0, 0, 1};
    int direy[4] = {0, -1, 1, 0};
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        vis[i][j] = 1;
        int res = 1, m = grid.size(), n = grid[0].size();
        for(int k = 0; k < 4; k++) {
            int ii = i + direx[k], jj = j + direy[k];
            if(inmap(ii, jj, m, n) && !vis[ii][jj] && grid[ii][jj]) {
                res += dfs(grid, ii, jj);
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};
