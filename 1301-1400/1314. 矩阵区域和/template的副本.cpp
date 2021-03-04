//
//  main.cpp
//  用二维前缀和，s[i][j]表示mat[0][0]到mat[i-1][j-1]这个矩阵的和
//  可以O(1)求出每个查询。处理一下边界情况即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + s[i - 1][j] + mat[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int row2 = min(i + K, m), col2 = min(j + K, n);
                int row1 = max(i - K, 1), col1 = max(j - K, 1);
                res[i - 1][j - 1] = s[row2][col2] - s[row1 - 1][col2] - s[row2][col1 - 1] + s[row1 - 1][col1 - 1];
            }
        }
        return res;
    }
};
