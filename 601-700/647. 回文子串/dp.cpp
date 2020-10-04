//
//  main.cpp
//  O(n^2)的dp
//  当然O(n^2)也可以用中心扩散法，即穷举回文串中心，然后计数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            res++;
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};
