//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string reformatNumber(string number) {
        string s, res;
        for (char c: number) {
            if (c != '-' && c != ' ') s.push_back(c);
        }
        int n = s.size(), i = 0;
        while (n - i > 4) {
            if (i) res.push_back('-');
            for (int j = i; j <= i + 2; j++) res.push_back(s[j]);
            i += 3;
        }
        if (i) res.push_back('-');
        for (int j = i; j < n; j++) {
            res.push_back(s[j]);
            if (j == i + 1 && n - i == 4) res.push_back('-');
        }
        return res;
    }
};
