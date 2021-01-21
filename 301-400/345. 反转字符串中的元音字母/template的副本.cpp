//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(char c) {
        if(isupper(c)) c += 'a' - 'A';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && f(s[l]) == 0) l++;
            while (l < r && f(s[r]) == 0) r--;
            if (l >= r) break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
