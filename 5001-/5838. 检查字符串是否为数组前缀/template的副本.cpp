//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res;
        for (auto &word: words) {
            res += word;
            if (res == s) return true;
        }
        return false;
    }
};
