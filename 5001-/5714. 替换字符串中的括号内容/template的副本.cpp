//
//  main.cpp
//  比较简单，字符串的基本操作
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &v: knowledge) {
            mp[v[0]] = v[1];
        }
        string res;
        int i = 0;
        while (i < s.size()) {
            if (s[i] != '(') {
                res.push_back(s[i++]);
            } else {
                int j = i;
                while (j < s.size() && s[j] != ')') j++;
                string key = s.substr(i + 1, j - i - 1);
                if (mp.count(key)) res += mp[key];
                else res.push_back('?');
                i = j + 1;
            }
        }
        return res;
    }
};
