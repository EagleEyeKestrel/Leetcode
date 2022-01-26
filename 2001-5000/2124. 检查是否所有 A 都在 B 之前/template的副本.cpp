//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkString(string s) {
        int l = -1, r = s.size();
        while (l + 1 < s.size() && s[l + 1] == 'a') l++;
        while (r - 1 >= 0 && s[r - 1] == 'b') r--;
        return r - l == 1;
    }
};