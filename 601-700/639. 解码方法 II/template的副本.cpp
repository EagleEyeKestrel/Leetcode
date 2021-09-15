//
//  main.cpp
//  比较无聊的dp。。全是数字的细节问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), mod = 1e9 + 7;
        long long dp[n];
        dp[0] = (s[0] == '*' ? 9 : 1);
        if (s[0] == '0') dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '*') {
                dp[i] = (dp[i - 1] * 9) % mod;
                if (s[i - 1] == '1') dp[i] = (dp[i] + 9 * (i >= 2 ? dp[i - 2] : 1)) % mod;
                if (s[i - 1] == '2') dp[i] = (dp[i] + 6 * (i >= 2 ? dp[i - 2] : 1)) % mod;
                if (s[i - 1] == '*') dp[i] = (dp[i] + 15 * (i >= 2 ? dp[i - 2] : 1)) % mod;
            } else if (s[i] == '0') {
                if (s[i - 1] == '*') dp[i] = (2 * (i >= 2 ? dp[i - 2] : 1)) % mod;
                else if (s[i - 1] == '2' || s[i - 1] == '1') dp[i] = (i >= 2 ? dp[i - 2] : 1) % mod;
                else dp[i] = 0;
            } else {
                dp[i] = dp[i - 1];
                if (s[i] <= '6') {
                    if (s[i - 1] == '*') dp[i] = (dp[i] + 2 * (i >= 2 ? dp[i - 2] : 1)) % mod;
                    else if (s[i - 1] == '2' || s[i - 1] == '1') dp[i] = (dp[i] + (i >= 2 ? dp[i - 2] : 1)) % mod;
                } else {
                    if (s[i - 1] == '*' || s[i - 1] == '1') dp[i] = (dp[i] + (i >= 2 ? dp[i - 2] : 1)) % mod;
                }
            }
        }
        return dp[n - 1];
    }
};
