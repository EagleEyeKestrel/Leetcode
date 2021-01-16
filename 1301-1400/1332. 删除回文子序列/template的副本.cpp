//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        if (!n) return 0;
        string ss = s;
        reverse(ss.begin(), ss.end());
        return ss == s ? 1 : 2;
    }
};
