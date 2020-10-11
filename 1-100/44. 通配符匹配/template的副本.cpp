//
//  main.cpp
//  经典的通配符匹配，dp[i][j]表示s前i个字符和p前j个字符
//  比较难的是*的处理，要么是空串，要么是任意字符
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
