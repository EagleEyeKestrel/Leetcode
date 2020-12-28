//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool f(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool halvesAreAlike(string s) {
        int n = s.size(), s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (f(s[i])) s1++;
            if (f(s[i + n / 2])) s2++;
        }
        return s1 == s2;
    }
};
