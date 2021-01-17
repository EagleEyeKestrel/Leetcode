//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxPower(string s) {
        int res = 0, tmp;
        for (int i = 0; i < s.size(); i++) {
            if (!i || s[i] != s[i - 1]) tmp = 1;
            else tmp++;
            res = max(res, tmp);
        }
        return res;
    }
};
