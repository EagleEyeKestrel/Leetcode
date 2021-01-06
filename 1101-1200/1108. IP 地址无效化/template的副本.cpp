//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char c: address) {
            if (c == '.') res += "[.]";
            else res.push_back(c);
        }
        return res;
    }
};
