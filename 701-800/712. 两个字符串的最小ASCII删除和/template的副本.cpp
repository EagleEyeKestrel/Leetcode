//
//  main.cpp
//  dp，和编辑距离类似，有点区别，但是思路是一致的
//  dp[i][j]表示s1前i个字符，s2前j个字符相等的最小删除和
//  当s1[i-1]==s2[j-1]，直接贪心保留
//  当不等，s1[i-1],s2[j-1]必定要删一个，那就取小的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for(int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(s1[i - 1] + dp[i - 1][j], s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
