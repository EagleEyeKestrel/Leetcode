//
//  main.cpp
//  马拉车算法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestPalindrome(string s) {
        char str[2048];
        int p[2048];
        for (int i = s.size(); i >= 0; i--) {
            str[2 * i + 2] = s[i];
            str[2 * i + 1] = '#';
        }
        str[0] = '\\';
        int mx = 0, id = 0, l = 2 * s.size(), maxv = 0, maxpos = 0;
        p[0] = 1;
        for (int i = 1; i <= l; i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (str[i + p[i]] == str[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i], id = i;
            }
        }
        for (int i = 1; i <= l; i++) {
            if (p[i] > maxv) {
                maxv = p[i];
                maxpos = i;
            }
        }
        string res;
        for (int i = maxpos - maxv + 1; i < maxpos + maxv; i++) {
            if (str[i] != '#') res.push_back(str[i]);
        }
        return res;
    }
};
