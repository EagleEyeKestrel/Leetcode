//
//  main.cpp
//  也没意思的题，就按规则模拟
//  先精确匹配，然后都换成小写匹配，最后把所有元音都换成'a'匹配
//  可以优化一下，因为只取列表里匹配的第一个，所以不需要string映射到一个列表
//  只需要映射到第一个单词就行
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int m = wordlist.size(), n = queries.size();
        vector<string> res;
        unordered_set<string> se(wordlist.begin(), wordlist.end());
        unordered_map<string, vector<string>> mp;
        unordered_map<string, vector<string>> mp2;
        for (string& word: wordlist) {
            string low = word;
            for (int i = 0; i < low.size(); i++) low[i] = tolower(low[i]);
            mp[low].push_back(word);
            for (int i = 0; i < low.size(); i++) {
                if (f(low[i])) low[i] = 'a';
            }
            mp2[low].push_back(word);
        }
        for (string s: queries) {
            if (se.count(s)) {
                res.push_back(s);
                continue;
            }
            string low = s;
            for (int i = 0; i < low.size(); i++) low[i] = tolower(low[i]);
            if (mp.count(low)) {
                res.push_back(mp[low][0]);
                continue;
            }
            for (int i = 0; i < low.size(); i++) {
                if (f(low[i])) low[i] = 'a';
            }
            if (mp2.count(low)) {
                res.push_back(mp2[low][0]);
            } else {
                res.push_back("");
            }
        }
        return res;
    }
};
