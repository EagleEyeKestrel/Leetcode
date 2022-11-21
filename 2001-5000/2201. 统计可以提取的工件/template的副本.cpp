//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        int grid[n][n];
        memset(grid, 0, sizeof(grid));
        for (auto &v: dig) {
            grid[v[0]][v[1]] = 1;
        }
        for (auto &t: artifacts) {
            int x1 = t[0], y1 = t[1], x2 = t[2], y2 = t[3];
            int flag = 1;
            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    if (!grid[x][y]) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) break;
            }
            res += flag;
        }
        return res;
    }
};