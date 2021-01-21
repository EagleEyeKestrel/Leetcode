//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkRecord(string s) {
        int flag1 = 0, flag2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') flag1++;
            if (s[i] == 'L') flag2++;
            else flag2 = 0;
            if (flag1 > 1 || flag2 > 2) return false;
        }
        return true;
    }
};
