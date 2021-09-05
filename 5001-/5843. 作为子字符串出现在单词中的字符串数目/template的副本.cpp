//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (string &s: patterns) {
            if (word.find(s) != string::npos) res++;
        }
        return res;
    }
};
