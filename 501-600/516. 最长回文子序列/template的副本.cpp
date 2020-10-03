//
//  main.cpp
//  基础的dp，dp[i][j]表示i到j最长回文子序列长度。用s[i]是否等于s[j]更新
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
