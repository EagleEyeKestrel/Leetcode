//
//  main.cpp
//  思路是穷举两列l,r，然后对于左右边界是l,r的矩形，可以维护一个矩阵和，就变成了最大子数组和问题
//  关键就是各种维护取到极值时的坐标
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        vector<int> respos;
        int s[m][n];
        for (int i = 0; i < m; i++) {
            s[i][0] = matrix[i][0];
            for (int j = 1; j < n; j++) s[i][j] = matrix[i][j] + s[i][j - 1];
        }
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                vector<int> v;
                for (int i = 0; i < m; i++) {
                    v.push_back(l ? s[i][r] - s[i][l - 1] : s[i][r]);
                }
                int tmpres = INT_MIN, tmps = 0, mins = 0, rmin = -1, r1 = -1, r2 = -1;
                for (int i = 0; i < m; i++) {
                    tmps += v[i];
                    if (tmps - mins > tmpres) {
                        tmpres = tmps - mins;
                        r1 = rmin + 1;
                        r2 = i;
                    }
                    if (tmps < mins) {
                        mins = tmps;
                        rmin = i;
                    }
                }
                if (res < tmpres) {
                    res = tmpres;
                    respos = {r1, l, r2, r};
                }
            }
        }
        return respos;
    }
};
