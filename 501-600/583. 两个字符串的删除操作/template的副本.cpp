//
//  main.cpp
//  简单的dp，显然我们要让两个字符串都删减得到最长公共子序列
//  可以去算最长公共子序列的长度，然后算差
//  或者直接用dp数组表示最少要删除的字母个数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return m - dp[m][n] + n - dp[m][n];
    }
};
