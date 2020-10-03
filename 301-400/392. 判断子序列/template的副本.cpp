//
//  main.cpp
//  双指针就行了，简单题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size(), l = 0, r = 0;
        if(!m) return true;
        while(l < m) {
            while(r < n && t[r] != s[l]) r++;
            if(r < n) {
                l++;
                r++;
            } else {
                return false;
            }
        }
        return true;
    }
};
