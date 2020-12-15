//
//  main.cpp
//  挺简单的，判断是不是一一对应。就是c++得手写一下split
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                tmp.push_back(s[i]);
            } else {
                v.push_back(tmp);
                tmp = "";
            }
        }
        if (tmp != "") v.push_back(tmp);
        unordered_map<char, string> m;
        unordered_map<string, char> re_m;
        int n = v.size();
        if (pattern.size() != n) return false;
        for (int i = 0; i < n; i++) {
            if (!m.count(pattern[i])) {
                m[pattern[i]] = v[i];
                if (re_m.count(v[i])) return false;
                re_m[v[i]] = pattern[i];
            } else {
                if (v[i] != m[pattern[i]]) return false;
            }
        }
        return true;
    }
};
