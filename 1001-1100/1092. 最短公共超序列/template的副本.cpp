//
//  main.cpp
//  其实就是普通的dp题，先用dp[i][j]表示str1[0...i-1]和str2【0...j-1]的超序列的最段长度
//  追踪数组t 0表示两个末尾相等 1表示取str1最后一个字母 2表示取str2
//  不能用dp数组来直接追踪采用哪一种情况。因为有的dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1算出来dp[i][j]也等于dp[i-1][j-1]+1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int dp[m + 1][n + 1], t[m + 1][n + 1];
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    t[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    if (dp[i - 1][j] < dp[i][j - 1]) t[i][j] = 1;
                    else t[i][j] = 2;
                }
            }
        }
        string res;
        int nowi = m, nowj = n;
        while (1) {
            if (nowi == 0 || nowj == 0) {
                while (nowi > 0 || nowj > 0) {
                    if (nowi > 0) res.push_back(str1[nowi - 1]), nowi--;
                    if (nowj > 0) res.push_back(str2[nowj - 1]), nowj--;
                }
                break;
            }
            if (t[nowi][nowj] == 0) {
                res.push_back(str1[nowi - 1]);
                nowi--, nowj--;
            } else if (t[nowi][nowj] == 1) {
                res.push_back(str1[nowi - 1]);
                nowi--;
            } else {
                res.push_back(str2[nowj - 1]);
                nowj--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
