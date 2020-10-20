//
//  main.cpp
//  dp的基础题。可以看s1的前m个字符和s2的前n个字符，如果匹配，一定匹配的是s3的前m+n个字符
//  然后看s3[m+n]和s1的第m个字符还是s2的第n个字符相等，推导出dp[i][j]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(s3.size() != m + n) return false;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = 0;
                if(s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if(j && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
