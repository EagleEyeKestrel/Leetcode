//
//  main.cpp
//  dp，用dp[i]表示以i结尾最长的有效括号字符串
//  如果s[i]是(，显然不行，dp[i]=0
//  如果是)，如果s[i-1]是(，那么就是dp[i-1]+2，否则s[i-1]无法匹配
//  否则，说明s当前末尾是))，找到dp[i-1]一段的之前, ...(...))
//  如果第一段省略号的末尾是(，说明最后一段可以变成((...))，再加上之前的最长的
//  如果第一段省略号的末尾是)，而第一段省略号的末尾的dp值一定是0，否则(...)还可以更长
//  这个）是无法被匹配的，所以这个dp[i]是0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || !i) continue;
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] + 2 : 2);
            } else {
                if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
