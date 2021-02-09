//
//  main.cpp
//  每一个长度为k的连续的“1”串，有k*(k+1)/2个子串。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSub(string s) {
        int n = s.size(), mod = 1e9 + 7;
        long long tmp = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') tmp++;
            else tmp = 0;
            if (i == n - 1 || s[i] == '1' && s[i + 1] == '0') {
                res = (res + tmp * (tmp + 1) / 2) % mod;
            }
        }
        return res;
    }
};
