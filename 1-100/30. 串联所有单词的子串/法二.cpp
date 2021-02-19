//
//  main.cpp
//  法二，滑动窗口
//  朴素方法中，存在着大量的重复计数，这里对每个起始点i做一个滑动窗口
//  比如当i为1，就每次加入单词[1,l],[l+1,2l]... 当达到n个单词之后，删除多余的单词out
//  要注意，这份代码里需要先删再加入新单词，否则会冲突
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size(), l = words[0].size(), cnt = 0;
        vector<int> res;
        unordered_map<string, int> mp;
        for (auto &word: words) mp[word]++;
        for (int i = 0; i < l; i++) {
            unordered_map<string, int> tmp;
            cnt = 0;
            for (int j = i; j + l <= s.size(); j += l) {
                if (j - n * l >= 0) {
                    string out = s.substr(j - n * l, l);
                    tmp[out]--;
                    if (mp.count(out) && tmp[out] >= 0 && tmp[out] < mp[out]) cnt--;
                }
                string now = s.substr(j, l);
                tmp[now]++;
                if (mp.count(now) && tmp[now] <= mp[now]) cnt++;
                if (cnt == n) res.push_back(j - (n - 1) * l);
            }
        }
        return res;
    }
};
