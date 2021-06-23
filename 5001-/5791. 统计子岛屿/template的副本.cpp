//
//  main.cpp
//  搜索题
//  也比较简单，先dfs一下grid2，处理出有多少个岛屿
//  然后对于每个岛屿，遍历一下全图，在无效的岛屿上进行标记。最后进行统计即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[510][510];
    int direx[4] = { -1, 0, 0, 1 };
    int direy[4] = { 0, -1, 1, 0 };
    int now = 0;
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid2) {
        vis[i][j] = now;
        for (int k = 0; k < 4; k++) {
            int ii = i + direx[k], jj = j + direy[k];
            if (inmap(ii, jj, m, n) && vis[ii][jj] == 0 && grid2[ii][jj]) {
                dfs(ii, jj, m, n, grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), res = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid2[i][j]) {
                    now++;
                    dfs(i, j, m, n, grid2);
                }
            }
        }
        int valid[now + 10];
        for (int i = 1; i <= now; i++) valid[i] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] && !grid1[i][j]) {
                    valid[vis[i][j]] = 0;
                }
            }
        }
        for (int i = 1; i <= now; i++) res += valid[i];
        return res;
    }
};
