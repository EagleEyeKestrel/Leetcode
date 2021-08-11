//
//  main.cpp
//  最简单的dp，dp[i]表示s[0...i]能否用字典拼成。穷举最后一个单词是从j-i即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i; j++) {
                string t = s.substr(j, i - j + 1);
                if (se.count(t)) {
                    if (j == 0) dp[i] = 1;
                    else dp[i] |= dp[j - 1];
                }
                if (dp[i] == 1) break;
            }
        }
        return dp[n - 1];
    }
};
