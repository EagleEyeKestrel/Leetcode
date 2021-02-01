//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size(), now = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (now) s[now++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') s[now++] = s[j++];
                reverse(s.begin() + now - j + i, s.begin() + now);
                i = j - 1;
            }
        }
        s.resize(now);
        return s;
    }
};
