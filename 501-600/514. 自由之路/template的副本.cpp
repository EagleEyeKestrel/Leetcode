//
//  main.cpp
//  比较简单的dp，用dp[i][j]表示 写到key[i] 并且ring停留在j处的 最小旋转次数
//  穷举上一次ring的状态k即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size(), minv = 1e9;
        int dp[n][m];
        for (int i = 0; i < m; i++) {
            if (ring[i] != key[0]) {
                dp[0][i] = 1e9;
                continue;
            }
            dp[0][i] = min(i, m - i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ring[j] != key[i]) {
                    dp[i][j] = 1e9;
                    continue;
                }
                dp[i][j] = 1e9;
                for (int k = 0; k < m; k++) {
                    if (dp[i - 1][k] != 1e9) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), m - abs(j - k)));
                    }
                }
            }
        }
        for (int j = 0; j < m; j++) minv = min(minv, dp[n - 1][j]);
        return minv + n;
    }
};
