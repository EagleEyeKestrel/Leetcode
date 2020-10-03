//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int put = min(rowSum[i] - row[i], colSum[j] - col[j]);
                res[i][j] = put;
                row[i] += put;
                col[j] += put;
            }
        }
        return res;
    }
};
