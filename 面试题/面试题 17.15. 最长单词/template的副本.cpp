//
//  main.cpp
//  先按长度排序，因为同长度要返回字典序最小的，所以同长度按字典逆序排
//  然后对每个单词，dp检查一下是否能由其他单词复合而来
//  用一个集合存储之前的所有单词。
//  复杂度O(n*m2)，n是列表长度，m是单词长度，不会超时，事实上跑出来也很快
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto &a, auto &b) {
            if (a.size() == b.size()) return a > b;
            return a.size() < b.size();
        });
        unordered_set<string> dict;
        string res;
        for (auto& word: words) {
            int n = word.size();
            int dp[n + 1];
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                dp[i] = 0;
                for (int j = 1; j <= i; j++) {
                    if (dp[i - j] && dict.count(word.substr(i - j, j))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            if (dp[n]) res = word;
            dict.insert(word);
        }
        return res;
    }
};
