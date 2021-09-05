//
//  main.cpp
//  比较简单的一个思路是，二分答案，然后朴素的多源bfs即可
//  比较好的思路应该是，并查集，从后往前，对新出现的陆地，合并新出现的陆地和周边已经存在的陆地。弄一个源点S，和汇点T，发现find(S)=find(T)，即为答案
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int m, n;
    struct node {
        int x, y;
        node (int _x, int _y) {
            x = _x, y = _y;
        }
    };
    int check(vector<vector<int>> &cells, int mid) {
        int grid[m][n], vis[m][n];
        memset(vis, 0, sizeof(vis));
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < mid; i++) grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        queue<node> q;
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) {
                node tmp(0, j);
                q.push(tmp);
                vis[0][j] = 1;
            }
        }
        while (!q.empty()) {
            node tmp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = tmp.x + dx[k], yy = tmp.y + dy[k];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || vis[xx][yy] || grid[xx][yy]) continue;
                if (xx == m - 1) return 1;
                q.push(node(xx, yy));
                vis[xx][yy] = 1;
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = cells.size();
        this->m = row, this->n = col;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(cells, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
