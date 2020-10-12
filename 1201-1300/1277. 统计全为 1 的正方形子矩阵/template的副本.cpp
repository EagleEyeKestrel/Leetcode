//
//  main.cpp
//  其实就是相比于计算最大的正方形矩阵，多了一步，每次算完dp[i][j]加一下个数
//  dp[i][j]表示(i - 1, j - 1)为右下角的最大正方形边长
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i - 1][j - 1]) {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
