//
//  main.cpp
//  dp[i][j][k]表示 第i+1次投掷 最后一下为j 并且最后有连续k个j的方案数
//  表面上看在更新状态时需要穷举上一次的所有jk，即复杂度5000*90*90 超时
//  但实际上，当k>1的时候上一次的j是确定的。只有看k=1需要穷举上一次的jk
//  所以复杂度是5000*6*6*15,不会超时
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int mod = 1e9 + 7;
        int dp[n][7][16];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i++) {
            dp[0][i][1] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 6; j++) {
                for (int k = 1; k <= rollMax[j - 1]; k++) {
                    if (k > 1) {
                        dp[i][j][k] = dp[i - 1][j][k - 1];
                    } else {
                        for (int lastj = 1; lastj <= 6; lastj++) {
                            if (lastj == j) continue;
                            for (int lastk = 1; lastk <= rollMax[lastj - 1]; lastk++) {
                                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][lastj][lastk]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= rollMax[j - 1]; k++) {
                res = (res + dp[n - 1][j][k]) % mod;
            }
        }
        return res;
    }
};
