//
//  main.cpp
//  看上去比较难。但我们思考一下这种步数问题能不能用dp解决
//  不难发现，对于一个矩形，切完一刀后留下来的肯定是右下角部分。
//  所以我们用dp[step][i][j] 表示(i,j)以及右下角部分，切step刀的方案数
//  然后我们穷举新的一刀是切y=jj 前 还是x=ii前，剩下的子问题就是dp[step-1][i][jj] 或者dp[step-1][ii][j]
//  然后就是需要判断这一刀是否有效。用d[i][j]表示(i,j)以下是否有苹果，r[i][j]表示(i,j)右边是否有苹果
//  这样就可以在穷举ii jj的过程中动态更新切下来的一刀是否有苹果了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        int dp[k][m][n], d[m][n], r[m][n];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; j++) {
            d[m - 1][j] = (pizza[m - 1][j] == 'A');
            for (int i = m - 2; i >= 0; i--) {
                d[i][j] = (pizza[i][j] == 'A') || d[i + 1][j];
            }
        }
        for (int i = 0; i < m; i++) {
            r[i][n - 1] = (pizza[i][n - 1] == 'A');
            for (int j = n - 2; j >= 0; j--) {
                r[i][j] = (pizza[i][j] == 'A') || r[i][j + 1];
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (pizza[i][j] == 'A') {
                    dp[0][i][j] = 1;
                    continue;
                }
                if (i < m - 1) dp[0][i][j] |= dp[0][i + 1][j];
                if (j < n - 1) dp[0][i][j] |= dp[0][i][j + 1];
            }
        }
        for (int step = 1; step < k; step++) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    int flag = 0;
                    for (int jj = j + 1; jj < n; jj++) {
                        flag |= d[i][jj - 1];
                        if (flag) dp[step][i][j] = (dp[step][i][j] + dp[step - 1][i][jj]) % mod;
                    }
                    flag = 0;
                    for (int ii = i + 1; ii < m; ii++) {
                        flag |= r[ii - 1][j];
                        if (flag) dp[step][i][j] = (dp[step][i][j] + dp[step - 1][ii][j]) % mod;
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};
