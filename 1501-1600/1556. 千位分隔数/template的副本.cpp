//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        string res = "";
        for (int i = 0; i < s.size(); i += 3) {
            if (s.size() - i > 3) {
                res = res + s.substr(i, 3) + ".";
            } else {
                res = res + s.substr(i);
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
