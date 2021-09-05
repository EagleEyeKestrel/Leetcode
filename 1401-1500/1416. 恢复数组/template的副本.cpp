//
//  main.cpp
//  比较简单的dp
//  dp[i]表示s[i]结尾有多少种。然后穷举最后一段的数字，不会超过10位
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7, res = 0;
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = i; j >= 0 && j >= i - 9; j--) {
                if (s[j] == '0') continue;
                long long num = stoll(s.substr(j, i - j + 1));
                if (num >= 1 && num <= k) {
                    dp[i] = (dp[i] + (j > 0 ? dp[j - 1] : 1)) % mod;
                }
                if (num > k) break;
            }
            res = (res + dp[i]) % mod;
        }
        return dp[n - 1];
    }
};
