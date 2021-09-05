//
//  main.cpp
//  偷鸡的方法是没想到如何预处理出来s[l1] s[l2]开始 长度为j的字符串谁大
//  直接处理确实不好处理。但是可以处理出lcp[i][j]
//  表示s[i] s[j]开始 有多少字符串是相同的 这样只需要比较一位就可以了
//  另外！这题居然卡memset，是我没想到的，
//  Copyright © 2021 ji luyang. All rights reserved.
//

int dp[3510][3510], s[3510][3510], lcp[3510][3510];
class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size(), mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) dp[i][j] = 0;
            for (int j = 0; j <= n; j++) s[i][j] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (num[i] == num[j]) {
                    if (i + 1 == n || j + 1 == n) lcp[i][j] = 1;
                    else lcp[i][j] = lcp[i + 1][j + 1] + 1;
                } else {
                    lcp[i][j] = 0;
                }
            }
        }
        if (num[0] != '0') dp[0][1] = 1;
        for (int j = 1; j <= n; j++) s[0][j] = s[0][j - 1] + dp[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i + 1; j++) {
                if (num[i - j + 1] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                if (i < j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = s[i - j][j - 1];
                    int l1 = i - j - j + 1, l2 = i - j + 1;
                    if (l1 < 0) continue;
                    if (lcp[l1][l2] >= j) dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
                    else {
                        int l = lcp[l1][l2];
                        if (num[l1 + l] < num[l2 + l]) dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
                    }
                }
            }
            s[i][0] = 0;
            for (int j = 1; j <= n; j++) s[i][j] = (s[i][j - 1] + dp[i][j]) % mod;
        }
        int res = 0;
        for (int j = 1; j <= n; j++) res = (res + dp[n - 1][j]) % mod;
        return res;
    }
};
