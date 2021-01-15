//
//  main.cpp
//  原题很简单，暴力就能过
//  这是O(mn)的方法，用dp
//  g[i][j]表示s[i] t[j]结尾的最长相同子串的长度
//  dp[i][j]表示s[i] t[j]结尾的需要替换1次才能相同的子串长度
//  还可以继续优化，把空间优化到O(1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), res = 0;
        int g[m + 1][n + 1], dp[m + 1][n + 1];
        memset(g, 0, sizeof(g));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = s[i - 1] == t[j - 1] ? g[i - 1][j - 1] + 1 : 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = g[i - 1][j - 1] + 1;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
