//
//  main.cpp
//  实际上暴力就能过了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = part.size();
        for (int i = 0; i < s.size(); i++) {
            res.push_back(s[i]);
            if (res.size() < n) continue;
            if (res.substr(res.size() - n, n) == part) {
                res = res.substr(0, res.size() - n);
            }
        }
        return res;
    }
};
