//
//  main.cpp
//  朴素方法，把words里的单词统计一下
//  然后检查s的每个位置看是否成立。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(), l = words[0].size();
        vector<int> res;
        unordered_map<string, int> mp;
        for (auto &word: words) mp[word]++;
        for (int i = 0; i <= (int)s.size() - n * l; i++) {
            unordered_map<string, int> tmp;
            int flag = 1;
            for (int j = 0; j < n; j++) {
                string str = s.substr(i + j * l, l);
                if (!mp.count(str) || tmp[str] >= mp[str]) {
                    flag = 0;
                    break;
                }
                tmp[str]++;
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};
