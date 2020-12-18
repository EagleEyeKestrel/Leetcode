//
//  main.cpp
//  
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {0, 1, 0, -1};
    int direy[4] = {1, 0, -1, 0};
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j < n && j >= 0;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int x = 0, y = 0, m = matrix.size(), n = matrix[0].size(), cnt = 0, k = 0;
        int vis[128][128];
        memset(vis, 0, sizeof(vis));
        vector<int> res;
        while (1) {
            res.push_back(matrix[x][y]);
            cnt++;
            if (cnt == m * n) break;
            vis[x][y] = 1;
            while(!inmap(x + direx[k], y + direy[k], m, n) || vis[x + direx[k]][y + direy[k]]) k = (k + 1) % 4;
            x += direx[k], y += direy[k];
        }
        return res;
    }
};
