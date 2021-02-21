//
//  main.cpp
//  bfs，水的深度是0，每个陆地的最高高度，其实就是到水的最短距离
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = { -1, 0, 0, 1 };
    int direy[4] = { 0, -1, 1, 0 };
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        queue<int> q;
        unordered_set<int> vis;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q.push(i * 1001 + j);
                    res[i][j] = 0;
                    vis.insert(i * 1001 + j);
                }
            }
        }
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            int x = tmp / 1001, y = tmp % 1001;
            for (int k = 0; k < 4; k++) {
                int xx = x + direx[k], yy = y + direy[k];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && !vis.count(1001 * xx + yy)) {
                    vis.insert(1001 * xx + yy);
                    res[xx][yy] = res[x][y] + 1;
                    q.push(1001 * xx + yy);
                }
            }
        }
        return res;
    }
};
