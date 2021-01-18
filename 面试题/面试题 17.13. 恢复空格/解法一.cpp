//
//  main.cpp
//  dp，一种方法是穷举单词，这道题遍历dict穷举最后一个单词比遍历j更快
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (auto& word: dictionary) {
                if (word.size() <= i) {
                    if (sentence.substr(i - word.size(), word.size()) == word) {
                        dp[i] = min(dp[i], dp[i - word.size()]);
                    }
                }
            }
        }
        return dp[n];
    }
};
