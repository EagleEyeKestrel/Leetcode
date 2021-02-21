//
//  main.cpp
//  int65536的解法
//  其实就是把word1和word2拼起来，然后找里面最长的回文子序列
//  满足原题意的子序列，只需要左端点在word1内，右端点在word2内！
//  Copyright © 2021 int65536. All rights reserved.
//

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string w = word1 + word2;
        int n = w.size();
        
        int dp[2010][2010] = {0};
        
        for (int i=0; i<n; ++i) dp[i][1] = 1;
        int res = 0;
        for (int len = 2; len<=n; ++len) {
            for (int i=0; i+len <=n; ++i) {
                if (w[i] == w[i+len-1]) {
                    dp[i][len] = 2 + dp[i+1][len-2];
                    if (i<n1 && i+len >n1) res = max(res, dp[i][len]);
                }
                else {
                    dp[i][len] = max( dp[i][len-1] , dp[i+1][len-1]);
                }
            }
        }
        return res;
    }
};
