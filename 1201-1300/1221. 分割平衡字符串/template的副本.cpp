//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, l = 0, r = 0;
        for (char c: s) {
            if (c == 'L') l++;
            else r++;
            if (l == r) {
                res++;
                l = 0, r = 0;
            }
        }
        return res;
    }
};
