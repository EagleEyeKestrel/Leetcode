//
//  main.cpp
//  l/up[i][j]记录grid[i][j]左侧/上侧最多有多少个连续的1
//  本来记录了四个方向。。实际上两个就可以了
//  然后穷举右下角的点(i,j)和边长k即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int l[m][n], up[m][n];
        for (int i = 0; i < m; i++) {
            l[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                l[i][j] = grid[i][j] ? l[i][j - 1] + 1 : 0;
            }
        }
        for (int j = 0; j < n; j++) {
            up[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                up[i][j] = grid[i][j] ? up[i - 1][j] + 1 : 0;
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; k <= min(i, j) + 1; k++) {
                    if (l[i][j] >= k && up[i][j] >= k && l[i - k + 1][j] >= k && up[i][j - k + 1] >= k) res = max(res, k);
                }
            }
        }
        return res * res;
    }
};
