//
//  main.cpp
//  mdzz，看了半天不知道query_glass是什么，原来是query的列号
//  其实就是个很简单的dp。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1) {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
