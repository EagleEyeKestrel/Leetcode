//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string replaceDigits(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2) {
                res.push_back(s[i - 1] + s[i] - '0');
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
