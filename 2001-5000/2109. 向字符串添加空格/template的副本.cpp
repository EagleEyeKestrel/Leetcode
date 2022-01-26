//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int id = 0;
        for (int i = 0; i < s.size(); i++) {
            if (id < spaces.size() && spaces[id] == i) res.push_back(' '), id++;
            res.push_back(s[i]);
        }
        return res;
    }
};
