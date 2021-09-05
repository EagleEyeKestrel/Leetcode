//
//  main.cpp
//  多源bfs问题，用vis[i][j]标记是否访问/离大陆最近的距离
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int x, y;
        node(int x_, int y_) {
            x = x_, y = y_;
        }
    };
    int vis[110][110];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), minv = 1, maxv = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = -1;
                minv = min(minv, grid[i][j]);
                maxv = max(maxv, grid[i][j]);
            }
        }
        if (minv == 1 || maxv == 0) return -1;
        queue<node> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push(node(i, j));
                    vis[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            node tmp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = tmp.x + dx[k], yy = tmp.y + dy[k];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || vis[xx][yy] != -1) continue;
                vis[xx][yy] = vis[tmp.x][tmp.y] + 1;
                q.push(node(xx, yy));
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, vis[i][j]);
            }
        }
        return res;
    }
};
