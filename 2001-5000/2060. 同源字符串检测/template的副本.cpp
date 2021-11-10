//
//  main.cpp
//  用dp[i][j]表示s1前i个字符，s2前j个字符，成功匹配，能相差的字符数集合
//  比如s2 和 ss匹配，那d就是1，表示第一个字符串还有一个自由字符
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_set<int> dp[41][41];
    bool possiblyEquals(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        dp[0][0] = {0};
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int d: dp[i][j]) {
                    int now = i, num = 0;
                    while (now < m && isdigit(s1[now])) {
                        num = num * 10 + s1[now] - '0';
                        dp[now + 1][j].insert(d + num);
                        now++;
                    }
                    now = j, num = 0;
                    while (now < n && isdigit(s2[now])) {
                        num = num * 10 + s2[now] - '0';
                        dp[i][now + 1].insert(d - num);
                        now++;
                    }
                    if (i < m && !isdigit(s1[i]) && d < 0) {
                        dp[i + 1][j].insert(d + 1);
                    }
                    if (j < n && !isdigit(s2[j]) && d > 0) {
                        dp[i][j + 1].insert(d - 1);
                    }
                    if (i < m && j < n && !isdigit(s1[i]) && s1[i] == s2[j] && d == 0) {
                        dp[i + 1][j + 1].insert(0);
                    }
                }
            }
        }
        return dp[m][n].count(0);
    }
};
