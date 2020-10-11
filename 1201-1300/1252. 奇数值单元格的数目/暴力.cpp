//
//  main.cpp
//  暴力方法
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int a[n][m];
        memset(a, 0, sizeof(a));
        for(auto &v: indices) {
            int r = v[0], c = v[1];
            for(int j = 0; j < m; j++) a[r][j] = !a[r][j];
            for(int i = 0; i < n; i++) a[i][c] = !a[i][c];
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res += a[i][j];
            }
        }
        return res;
    }
};
