//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int now = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] != s[i - 1]) now = 1;
            else now++;
            if (now <= 2) res.push_back(s[i]);
        }
        return res;
    }
};
