//
//  main.cpp
//  暴力做了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size(), maxl = 0, maxpos = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int tmp[128];
                memset(tmp, 0, sizeof(tmp));
                for (int k = i; k <= j; k++) {
                    tmp[s[k - 1]]++;
                }
                int flag = 1;
                for (int k = 0; k < 26; k++) {
                    if (tmp['a' + k] && !tmp['A' + k] || !tmp['a' + k] && tmp['A' + k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag && j - i + 1 > maxl) {
                    maxl = j - i + 1;
                    maxpos = i;
                }
            }
        }
        return maxl > 0 ? s.substr(maxpos - 1, maxl) : "";
    }
};
