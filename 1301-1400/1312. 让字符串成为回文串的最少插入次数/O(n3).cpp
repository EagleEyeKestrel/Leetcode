//
//  main.cpp
//  第一遍写了个O(n3)的。。还过了
//  穷举最后字符串的中心字符（1个或2个）
//  1个的情形，求出两边字符串最多几个字符回文（相当于最长公共子串问题），然后添加不同的
//  2个的情形，注意，两个字符一定都是相等的（也是原来s就有的），因为如果有一个是新加的字符，这个字符完全可以不加
// 
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& a, string& b) {
        int m = a.size(), n = b.size();
        if (!m || !n) return 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        int n = s.size(), res = n - 1;
        for (int i = 0; i < n; i++) {
            string s1 = s.substr(0, i), s2 = s.substr(i + 1);
            reverse(s1.begin(), s1.end());
            res = min(res, n - 1 - 2 * f(s1, s2));
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                string s1 = s.substr(0, i + 1), s2 = s.substr(i + 1);
                reverse(s1.begin(), s1.end());
                res = min(res, n - 2 * f(s1, s2));
            }
        }
        return res;
    }
};
