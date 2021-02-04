//
//  main.cpp
//  第一种，本身是回文串
//  或者，找到第一对不相等的，然后删除其一，看是否回文
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string &s) {
        int n = s.size();
        int l = 0, r = n - 1, flag = 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++, r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        if (f(s)) return true;
        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                string s1 = s.substr(0, l) + s.substr(l + 1, n - l - 1);
                string s2 = s.substr(0, r) + s.substr(r + 1, n - r - 1);
                if (f(s1) || f(s2)) return true;
                return false;
            }
            l++, r--;
        }
        return false;
    }
};
