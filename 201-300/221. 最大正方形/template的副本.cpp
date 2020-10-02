//
//  main.cpp
//  简单的dp，注意dp方程里必须还有dp[i - 1][j - 1]，因为前两项不足以保证(i,j)左上角也是一个正方形
//  这题我居然WA了三次。。第一次是没发现是char数组，第二次是没发现应该返回面积
//  第三次是脑子不知道怎么的以为矩阵也是正方形。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size(), res = 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};
