//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        string res;
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') res.push_back(c);
            else {
                if (res.empty() || res.back() != mp[c]) return false;
                res.pop_back();
            }
        }
        return res.empty();
    }
};
