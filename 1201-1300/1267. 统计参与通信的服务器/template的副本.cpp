//
//  main.cpp
//  简单题，统计一下每行和每列的机器个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !(row[i] == 1 && col[j] == 1)) res++;
            }
        }
        return res;
    }
};
