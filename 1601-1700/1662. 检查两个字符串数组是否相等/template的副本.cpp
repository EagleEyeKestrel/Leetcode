//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1 = "", res2 = "";
        for(auto s1: word1) res1 = res1 + s1;
        for(auto s2: word2) res2 = res2 + s2;
        return res1 == res2;
    }
};
