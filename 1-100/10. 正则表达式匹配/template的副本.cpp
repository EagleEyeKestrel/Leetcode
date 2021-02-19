//
//  main.cpp
//  显然是dp，关键是边界条件和细节的处理
//  首先处理初始状态。主要是dp[0][j]，看p能不能匹配空串
//  p匹配空串意味着，dp[0][j-2]可以匹配空串，然后... a*最后一个字是*
//  然后主要也是对*的处理，一种情况*取0个，直接是dp[i][j-2]
//  另一种情况就是p[j-2]==s[i-1]并且dp[i-1][j]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = (j >= 2 && dp[0][j - 2] && p[j - 1] == '*');
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    dp[i][j] |= (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                } else if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
