//
//  main.cpp
//  处理题，先处理出所有的单词，然后统计最大次数。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        vector<string> v;
        int maxv = 0, n = paragraph.size(), i = 0;
        while (i < n) {
            while (i < n && !isalpha(paragraph[i])) i++;
            if (i >= n) break;
            int j = i;
            while (j < n && isalpha(paragraph[j])) j++;
            v.push_back(paragraph.substr(i, j - i));
            i = j + 1;
        }
        unordered_map<string, int> mp;
        for (string word: v) {
            for (int i = 0; i < word.size(); i++) word[i] = tolower(word[i]);
            if (ban.count(word)) continue;
            mp[word]++;
            maxv = max(maxv, mp[word]);
        }
        for (auto it: mp) {
            if (it.second == maxv) return it.first;
        }
        return "";
    }
};
