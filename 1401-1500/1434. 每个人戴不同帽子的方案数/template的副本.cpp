//
//  main.cpp
//  这里显然是状压dp。但如何确定dp数组是最关键的
//  如果用dp[i][j]表示前i个人 帽子状态为j 那么帽子大小显然不能状压
//  所以从反面来考虑 表示前i个帽子 分完之后当前人的状态是j 就可以状压了
//  转移方程见注释
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int mod = 1e9 + 7;
        //dp[i][j]: 前i个帽子 人是j状态
        //i不分 dp[i-1][j]
        //i分 k dp[i-1][j ^ (1 << k)]
        int n = hats.size();
        int vis[n][41], dp[50][1 << n];
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int hat: hats[i]) vis[i][hat] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[1][1 << j] = vis[j][1];
        }
        dp[1][0] = 1;
        for (int i = 2; i <= 40; i++) {
            dp[i][0] = 1;
            for (int mask = 1; mask < 1 << n; mask++) {
                dp[i][mask] = dp[i - 1][mask];
                for (int j = 0; j < n; j++) {
                    if ((mask >> j & 1) && vis[j][i]) {
                        dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << j)]) % mod;
                    }
                }
            }
        }
        return dp[40][(1 << n) - 1];
    }
};
