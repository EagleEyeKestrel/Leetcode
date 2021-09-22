//
//  main.cpp
//  偷鸡代码...这是一份O(n3)的代码
//  dp[i][j]表示 num[0...i]中，最后一个数字长度为j的方案数
//  显然可以穷举上一个数字的长度是1,2,...j-1 都可以直接加，关键还有长度为j的
//  当时没想到什么直接预处理的办法。考虑到直接往两边搜索，需要搜索长度比较大的情况大多都是全重复的数字
//  于是用maxl[i]表示 i的左侧和右侧 最长多少长度 数字都相等
//  这样可以判断maxl[r1]>=j进行优化。没想到就直接过了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size(), mod = 1e9 + 7;
        int dp[n][n + 1], s[n][n + 1];
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        int maxl[n];
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1, tmp = 0;
            while (l >= 0 && r < n && num[l] == num[r] && (r - l == 1 || num[l] == num[l + 1])) tmp++, l--, r++;
            maxl[i] = tmp;
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
                    int l1 = i - j - j + 1, r1 = l1 + j - 1, l2 = i - j + 1, r2 = i;
                    if (l1 < 0) continue;
                    if (maxl[r1] >= j) {
                        dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
                        continue;
                    }
                    int res = 1, p = 0;
                    while (p < j) {
                        if (num[l1 + p] < num[l2 + p]) {
                            res = 1;
                            break;
                        }
                        if (num[l1 + p] > num[l2 + p]) {
                            res = 0;
                            break;
                        }
                        p++;
                    }
                    if (res) dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
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
