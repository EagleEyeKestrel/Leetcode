//
//  main.cpp
//  我比赛时候的做法，没有能想到拼接word1 word2，但也做出来了
//  看复杂度大概是O(mn)，想到最长公共子串问题
//  于是把word2倒转过来，求word1 word2的最长公共子串
//  然后可以预处理word1 word2每一段范围内最长回文子序列的长度
//  找完最长公共子序列，可以在word1 i之后的部分找一个回文子序列，加在两段的中间
//  或者在word2 j之后的部分找一个回文子序列，同样也加在两段中间
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int m = word1.size(), n = word2.size(), res = 0;
        int p1[m + 1][m + 1], p2[n + 1][n + 1];
        reverse(word2.begin(), word2.end());
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        for (int i = 1; i <= m; i++) p1[i][i] = 1;
        for (int i = m - 1; i >= 1; i--) {
            for (int j = i + 1; j <= m; j++) {
                if (word1[i - 1] == word1[j - 1]) p1[i][j] = 2 + p1[i + 1][j - 1];
                else p1[i][j] = max(p1[i + 1][j], p1[i][j - 1]);
            }
        }
        for (int i = 1; i <= n; i++) p2[i][i] = 1;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                if (word2[i - 1] == word2[j - 1]) p2[i][j] = 2 + p2[i + 1][j - 1];
                else p2[i][j] = max(p2[i + 1][j], p2[i][j - 1]);
            }
        }
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                int tmp = 2 * dp[i][j];
                if (tmp) {
                    int val = tmp;
                    if (i < m) tmp = max(tmp, val + p1[i + 1][m]);
                    if (j < n) tmp = max(tmp, val + p2[j + 1][n]);
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
