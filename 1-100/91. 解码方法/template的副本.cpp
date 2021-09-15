//
//  main.cpp
//  简单的dp，讨论的可能有点麻烦。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), res = 0;
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '0') {
                if (s[i - 2] == '2' || s[i - 2] == '1') dp[i] = dp[i - 2];
                else return 0;
            } else if (s[i - 1] <= '6') {
                if (s[i - 2] == '2' || s[i - 2] == '1') dp[i] = dp[i - 2] + dp[i - 1];
                else dp[i] = dp[i - 1];
            } else {
                if (s[i - 2] == '1') dp[i] = dp[i - 2] + dp[i - 1];
                else dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
