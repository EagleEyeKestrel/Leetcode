//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (!n) return 0;
        int isPalindrome[n][n];
        for (int i = 0; i < n; i++) isPalindrome[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isPalindrome[i][j] = (s[i] == s[j] && (isPalindrome[i + 1][j - 1] || j <= i + 2));
            }
        }
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = i + 1;
            for (int j = i; j >= 0 ; j--) {
                if (isPalindrome[j][i]) {
                    dp[i] = min(dp[i], j ? dp[j - 1] + 1 : 1);
                }
            }
        }
        return dp[n - 1] - 1;
    }
};
