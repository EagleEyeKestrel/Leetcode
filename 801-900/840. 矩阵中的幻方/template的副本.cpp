//
//  main.cpp
//  没想到什么简便方法，穷举了八种幻方，然后中心肯定是5，检查所有5的周边
//  当然也可以去计算八个和
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
    int direy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
    vector<vector<int>> v = {
        { 8, 1, 6, 3, 5, 7, 4, 9, 2 },
        { 6, 1, 8, 7, 5, 3, 2, 9, 4 },
        { 4, 9, 2, 3, 5, 7, 8, 1, 6 },
        { 2, 9, 4, 7, 5, 3, 6, 1, 8 },
        { 6, 7, 2, 1, 5, 9, 8, 3, 4 },
        { 8, 3, 4, 1, 5, 9, 6, 7, 2 },
        { 2, 7, 6, 9, 5, 1, 4, 3, 8 },
        { 4, 3, 8, 9, 5, 1, 2, 7, 6 }
    };
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 5) {
                    for (int k = 0; k < 8; k++) {
                        int flag = 1;
                        for (int t = 0; t < 9; t++) {
                            int ii = i + direx[t], jj = j + direy[t];
                            if (grid[ii][jj] != v[k][t]) {
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            res++;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
