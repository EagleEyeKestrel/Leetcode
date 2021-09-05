//
//  main.cpp
//  没注意行列相等。老题了，复杂度O(n^3)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int up[m][n], l[m][n];
        for (int i = 0; i < m; i++) {
            l[i][0] = 1 - matrix[i][0];
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) l[i][j] = l[i][j - 1] + 1;
                else l[i][j] = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            up[0][j] = 1 - matrix[0][j];
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == 0) up[i][j] = up[i - 1][j] + 1;
                else up[i][j] = 0;
            }
        }
        vector<int> res = {};
        for (int sz = 1; sz <= m; sz++) {
            for (int i = sz - 1; i < m; i++) {
                for (int j = sz - 1; j < n; j++) {
                    int flag = l[i][j] >= sz && l[i - sz + 1][j] >= sz && up[i][j] >= sz && up[i][j - sz + 1] >= sz;
                    if (!flag) continue;
                    if (res.empty() || sz > res[2]) {
                        res = {i - sz + 1, j - sz + 1, sz};
                    }
                }
            }
        }
        return res;
    }
};
