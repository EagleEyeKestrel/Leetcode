//
//  main.cpp
//  O(n)的马拉车，这题用马拉车几乎就是秒了，每次加上p[i] / 2即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        char str[2 * n + 3];
        int p[2 * n + 2];
        str[0] = '\\';
        for(int i = 1; i <= n; i++) {
            str[2 * i - 1] = '#';
            str[2 * i] = s[i - 1];
        }
        str[2 * n + 1] = '#';
        str[2 * n + 2] = '\0';
        p[0] = 1;
        int mx = 0, id = 0, res = 0;
        for(int i = 1; i <= 2 * n + 1; i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(str[i + p[i]] == str[i - p[i]]) p[i]++;
            if(i + p[i] > mx) {
                id = i;
                mx = i + p[i];
            }
            res += p[i] / 2;
        }
        return res;
    }
};
