//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& word, string& pattern) {
        unordered_map<char, char> mp;
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < word.size(); i++) {
            if (mp.count(word[i]) && mp[word[i]] != pattern[i]) {
                return 0;
            }
            if (!mp.count(word[i])) {
                mp[word[i]] = pattern[i];
                if (cnt[pattern[i]]) return 0;
                cnt[pattern[i]]++;
            }
        }
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string &word: words) {
            if (f(word, pattern)) res.push_back(word);
        }
        return res;
    }
};
