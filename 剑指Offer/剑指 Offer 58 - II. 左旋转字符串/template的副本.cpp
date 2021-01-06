//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size() - n) + s.substr(0, n);
    }
};
