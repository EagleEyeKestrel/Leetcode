//
//  main.cpp
//  dp[i][j]表示当有i个骰子，投出j+1的概率
//  计算dp[i][j]时，穷举最后一个骰子投出的是1-6中哪一个即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp[12];
        dp[1] = vector<double>(6, (double)1 / 6);
        for (int i = 2; i <= n; i++) {
            dp[i] = vector<double>(6 * i, 0);
            for (int j = 1; j <= 6 * i; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j - k <= 0 || j - k > dp[i - 1].size()) continue;
                    dp[i][j - 1] += (double)1 / 6 * dp[i - 1][j - k - 1];
                }
            }
        }
        dp[n].erase(dp[n].begin(), dp[n].begin() + n - 1);
        return dp[n];
    }
};
