//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < n && !isalnum(s[l])) l++;
            while (r >= 0 && !isalnum(s[r])) r--;
            if (l >= r) return true;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++, r--;
        }
        return true;
    }
};
