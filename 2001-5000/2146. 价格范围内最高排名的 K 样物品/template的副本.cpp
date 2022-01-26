//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int m, n;
    bool inmap(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        vector<pair<int, int>> v;
        int vis[m][n];
        memset(vis, -1, sizeof(vis));
        vis[start[0]][start[1]] = 0;
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int X = tmp.first, Y = tmp.second;
            if (grid[X][Y] >= pricing[0] && grid[X][Y] <= pricing[1]) {
                v.push_back({X, Y});
            }
            for (int k = 0; k < 4; k++) {
                int x = X + dx[k], y = Y + dy[k];
                if (inmap(x, y) && vis[x][y] == -1 && grid[x][y] > 0) {
                    q.push({x, y});
                    vis[x][y] = vis[X][Y] + 1;
                }
            }
        }
        sort(v.begin(), v.end(), [&](auto &p1, auto &p2) {
            int x1 = p1.first, y1 = p1.second;
            int x2 = p2.first, y2 = p2.second;
            if (vis[x1][y1] == vis[x2][y2] && grid[x1][y1] == grid[x2][y2] && x1 == x2) return y1 < y2;
            if (vis[x1][y1] == vis[x2][y2] && grid[x1][y1] == grid[x2][y2]) return x1 < x2;
            if (vis[x1][y1] == vis[x2][y2]) return grid[x1][y1] < grid[x2][y2];
            return vis[x1][y1] < vis[x2][y2];
        });
        if (v.size() > k) v.erase(v.begin() + k, v.end());
        vector<vector<int>> res;
        for (auto &pi: v) res.push_back({pi.first, pi.second});
        return res;
    }
};