//
//  main.cpp
//  dp[i]表示恰好以i结尾 且之前未出现过的子序列
//  和 不同的子序列II一题类似，只不过需要前缀和优化一下
//  最后额外判断一下序列‘0’
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size(), res = 0;
        int dp[n], sum[n];
        dp[0] = binary[0] - '0';
        sum[0] = dp[0];
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && binary[j] != binary[i]) j--;
            if (j == -1 && binary[i] == '1') dp[i] = 1;
            else dp[i] = 0;
            if (j == -1) j++;
            dp[i] += ((j == 0) ? sum[i - 1] : sum[i - 1] - sum[j - 1]);
            dp[i] = (dp[i] + mod) % mod;
            sum[i] = (sum[i - 1] + dp[i]) % mod;
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                flag = 1;
                break;
            }
        }
        return (sum[n - 1] + flag) % mod;;
    }
};
