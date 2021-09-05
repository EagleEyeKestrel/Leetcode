//
//  main.cpp
//  前几天刚遇到，是ABC round 214 F题的弱版。这道题就很简单了
//  用dp[i]表示以s[i]结尾的子序列，且之前没出现过
//  找到之前一个字符同样是s[i]的位置。dp[i]就等于之间这一段，因为只有这一段加上s[i]才有意义
//  之前的一段 如果加s[i] 可以加之前的位置 那就重复了。另外考虑初始化
//  前缀和优化一下就变成O(n)了。如果都是小写字母的话
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        int dp[n], sum[n];
        dp[0] = 1, sum[0] = 1;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && s[j] != s[i]) j--;
            dp[i] = (j == -1 ? 1 : 0);
            if (j == -1) j++;
            dp[i] = ((j == 0 ? sum[i - 1] : sum[i - 1] - sum[j - 1]) + dp[i] + mod) % mod;
            //for (int k = j; k < i; k++) dp[i] = (dp[i] + dp[k]) % mod;
            sum[i] = (sum[i - 1] + dp[i]) % mod;
        }
        return sum[n - 1];
    }
};
