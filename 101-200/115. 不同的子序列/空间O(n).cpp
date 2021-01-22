//
//  main.cpp
//  补一个空间O(n)版本
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = n; j > 0; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};
