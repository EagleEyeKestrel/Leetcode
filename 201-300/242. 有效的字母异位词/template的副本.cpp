//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(t.begin(), t.end());
        sort(s.begin(), s.end());
        return s == t;
    }
};
