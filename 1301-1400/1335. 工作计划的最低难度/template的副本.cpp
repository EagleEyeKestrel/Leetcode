//
//  main.cpp
//  比较基础的dp。用dp[i][j]表示将前i个任务分成j天的最小困难和。
//  然后穷举最后一天是k-j，之前j-1天的困难和就是dp[k-1][j-1]
//  第k-j天的最大困难值，可以预处理出一个maxv数组，maxv[i][j]表示从jobi到jobj的最大困难值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        int dp[n][d + 1], maxv[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= d; j++) dp[i][j] = INT_MAX;
        }
        for (int i = 0; i < n; i++) maxv[i][i] = jobDifficulty[i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                maxv[i][j] = max(maxv[i + 1][j], jobDifficulty[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][1] = maxv[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 2; j <= min(d, i + 1); j++) {
                for (int k = j - 1; k <= i; k++) {
                    if (k == 0) {
                        dp[i][j] = max(dp[i][j], maxv[k][i]);
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + maxv[k][i]);
                }
            }
        }
        return dp[n - 1][d] == INT_MAX ? -1 : dp[n - 1][d];
    }
};
