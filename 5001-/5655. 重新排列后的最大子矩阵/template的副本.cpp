//
//  main.cpp
//  先得到每一行的滚动数组h[j]，表示当前matrix[i][j]以上连续的1的个数
//  对于每一行，从大到小排序，第j列可以和第0到j-1列组成矩阵。
//  高是tmp_h[j],长是j+1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        int h[n], tmp_h[n];
        memset(h, 0, sizeof(h));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h[j] = matrix[i][j] ? h[j] + 1 : 0;
            }
            memcpy(tmp_h, h, n * sizeof(int));
            sort(tmp_h, tmp_h + n, greater<int>());
            for (int j = 0; j < n; j++) {
                res = max(res, tmp_h[j] * (j + 1));
            }
        }
        return res;
    }
};
