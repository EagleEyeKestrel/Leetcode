//
//  main.cpp
//  比较容易的dp，但是写个方向向量会更好一点
//  用dp表示最大得分，然后遍历三个方向，res用来计数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size(), mod = 1e9 + 7;
        int dp[m][n], res[m][n];
        dp[m - 1][n - 1] = 0;
        board[0][0] = '0';
        for (int j = n - 2; j >= 0; j--) {
            if (dp[m - 1][j + 1] == -1) dp[m - 1][j] = -1;
            else if (board[m - 1][j] == 'X') dp[m - 1][j] = -1;
            else dp[m - 1][j] = dp[m - 1][j + 1] + board[m - 1][j] - '0';
        }
        for (int i = m - 2; i >= 0; i--) {
            if (dp[i + 1][n - 1] == -1 || board[i][n - 1] == 'X') dp[i][n - 1] = -1;
            else dp[i][n - 1] = dp[i + 1][n - 1] + board[i][n - 1] - '0';
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 'X') dp[i][j] = -1;
                else {
                    dp[i][j] = -1;
                    int score = board[i][j] - '0';
                    if (dp[i + 1][j] != -1) dp[i][j] = max(dp[i][j], dp[i + 1][j] + score);
                    if (dp[i][j + 1] != -1) dp[i][j] = max(dp[i][j], dp[i][j + 1] + score);
                    if (dp[i + 1][j + 1] != -1) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + score);
                }
            }
        }
        if (dp[0][0] == -1) return {0, 0};
        res[m - 1][n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            if (dp[m - 1][j] == -1) res[m - 1][j] = 0;
            else res[m - 1][j] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            if (dp[i][n - 1] == -1) res[i][n - 1] = 0;
            else res[i][n - 1] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                res[i][j] = 0;
                int score = board[i][j] - '0';
                if (dp[i][j] == score + dp[i + 1][j]) res[i][j] = (res[i][j] + res[i + 1][j]) % mod;
                if (dp[i][j] == score + dp[i][j + 1]) res[i][j] = (res[i][j] + res[i][j + 1]) % mod;
                if (dp[i][j] == score + dp[i + 1][j + 1]) res[i][j] = (res[i][j] + res[i + 1][j + 1]) % mod;
            }
        }
        return {dp[0][0], res[0][0]};
    }
};
