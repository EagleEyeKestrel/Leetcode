//
//  main.cpp
//  枚举两个字符串然后拼接，复杂度n^2 m，肯定超时的
//  这里对每个字符串，枚举它的所有前缀/后缀
//  即，每次考虑长度更大的wordi，对于一组wordi+wordj
//  可以是wordi的一个后缀作为中间回文串，然后wordi剩下的前缀和wordj对称
//  或者反过来，公用wordi的前缀，wordi的后缀和wordj对称
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return 0;
            l++, r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) mp[words[i]] = i;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (mp.count(rev) && mp[rev] != i) {
                res.push_back({ i, mp[rev] });
            }
            for (int l = 1; l <= word.size(); l++) {
                string s1 = rev.substr(l), s2 = rev.substr(0, word.size() - l);
                if (f(word, word.size() - l, word.size() - 1) && mp.count(s1)) {
                    res.push_back({ i, mp[s1] });
                }
                if (f(word, 0, l - 1) && mp.count(s2)) {
                    res.push_back({ mp[s2], i });
                }
            }
        }
        return res;
    }
};
