//
//  main.cpp
//  另一种方法，穷举最后一个单词，看这个单词是否在dict内
//  照理是O(n2)的不超时，确实不超时，但很慢
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        int maxlen = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            maxlen = max(maxlen, (int)(*it).size());
        }
        int n = sentence.size();
        if (!n) return 0;
        int dp[n + 1];
        for (int i = 1; i <= n; i++) dp[i] = 1 << 30;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(maxlen, i); j++) {
                if (s.count(sentence.substr(i - j, j))) {
                    dp[i] = min(dp[i], dp[i - j]);
                }
                else dp[i] = min(dp[i], dp[i - j] + j);
            }
        }
        return dp[n];
    }
};
