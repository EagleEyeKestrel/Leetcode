//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int i = 0;
        while (i < s.size()) {
            if (i < s.size() - 2 && s[i + 2] == '#') {
                int tmp = 10 * (s[i] - '0') + s[i + 1] - '0';
                res.push_back(tmp - 10 + 'j');
                i += 3;
            } else {
                res.push_back(s[i] - '1' + 'a');
                i++;
            }
        }
        return res;
    }
};
