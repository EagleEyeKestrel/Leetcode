//
//  main.cpp
//  马拉车算法
//  p[i]表示str[i]的回文半径
//  真实的回文串长度是p[i] / 2(p[i]一定为奇数)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        char str[2 * n + 3];
        str[0] = '$';
        for (int i = 1; i <= n; i++) {
            str[2 * i - 1] = '#';
            str[2 * i] = s[i - 1];
        }
        str[2 * n + 1] = '#';
        str[2 * n + 2] = '\0';
        int p[2 * n + 3];
        p[0] = 1;
        int mx = 0, id = 0;
        for (int i = 1; i <= 2 * n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while (str[i + p[i]] == str[i - p[i]])
                p[i]++;
            if (i + p[i] - 1 > mx) {
                mx = i + p[i] - 1;
                id = i;
            }
        }
        int maxpos = -1, maxlen = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (p[i] > maxlen) {
                maxlen = p[i];
                maxpos = i;
            }
        }
        string res;
        for (int i = maxpos - maxlen + 1; i <= maxpos + maxlen - 1; i++) {
            if (str[i] != '#') {
                res.push_back(str[i]);
            }
        }
        return res;
    }
};
