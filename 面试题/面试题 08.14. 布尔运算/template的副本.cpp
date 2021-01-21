//
//  main.cpp
//  比较经典的区间dp。题目对复杂度要求也很低
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countEval(string s, int result) {
        vector<int> num;
        vector<char> op;
        for (char c: s) {
            if (c >= '0' && c <= '9') num.push_back(c - '0');
            else op.push_back(c);
        }
        int n = num.size();
        int dp[n][n][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][i][num[i]]++;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    if (op[k] == '&') {
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][0];
                    }
                    if (op[k] == '|') {
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
                        dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                    }
                    if (op[k] == '^') {
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
                        dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                        dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][1];
                    }
                }
            }
        }
        return dp[0][n - 1][result];
    }
};
