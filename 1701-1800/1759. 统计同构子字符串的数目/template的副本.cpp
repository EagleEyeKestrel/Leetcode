//
//  main.cpp
//  处理每一个连续的字母序列，长度为k的贡献为1+2+...+k
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), mod = 1e9 + 7, tmp;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (!i || s[i] != s[i - 1]) tmp = 1;
            else tmp++;
            if (i == n - 1 || s[i] != s[i + 1]) {
                res = (res + (long long)tmp * (tmp + 1) / 2) % mod;
            }
        }
        return res;
    }
};
