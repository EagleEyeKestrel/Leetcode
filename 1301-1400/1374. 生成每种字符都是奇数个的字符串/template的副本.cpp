//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string generateTheString(int n) {
        string res;
        int nn = n % 2 ? n : n - 1;
        for (int i = 0; i < nn; i++) res.push_back('a');
        if (nn < n) res.push_back('b');
        return res;
    }
};
