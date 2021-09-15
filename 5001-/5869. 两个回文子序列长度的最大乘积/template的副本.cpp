//
//  main.cpp
//  最基础的状压。。但是居然一定要预处理，不预处理交了超时了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return 0;
            l++, r--;
        }
        return 1;
    }
    int maxProduct(string s) {
        int n = s.size(), res = 1;
        int p[4096];
        for (int mask = 1; mask < 1 << n; mask++) {
            string tmp;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) tmp.push_back(s[i]);
            }
            p[mask] = f(tmp);
        }
        for (int mask = 1; mask < 1 << n; mask++) {
            for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
                int other = mask ^ sub;
                if (p[sub] && p[other]) {
                    int x = __builtin_popcount(sub), y = __builtin_popcount(other);
                    res = max(res, x * y);
                }
            }
        }
        return res;
    }
};
