//
//  main.cpp
//  太迷了，mp裸题，居然是困难，之前我记得有要用kmp还是简单的题。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int p[n + 1];
        p[0] = 0, p[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i];
            while (j && s[i] != s[j]) j = p[j];
            p[i + 1] = (s[i] == s[j] ? j + 1 : 0);
        }
        return s.substr(0, p[n]);
    }
};
