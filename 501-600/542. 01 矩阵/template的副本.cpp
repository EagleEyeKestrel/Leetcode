//
//  main.cpp
//  多源bfs，把所有的0放入队列，然后进行bfs
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    struct node {
        int x, y;
        node(int x_, int y_) {
            x = x_, y = y_;
        }
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<node> q;
        vector<vector<int>> res(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push(node(i, j));
                    res[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            node tmp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = tmp.x + dx[k], yy = tmp.y + dy[k];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || res[xx][yy] != -1) continue;
                q.push(node(xx, yy));
                res[xx][yy] = res[tmp.x][tmp.y] + 1;
            }
        }
        return res;
    }
};
