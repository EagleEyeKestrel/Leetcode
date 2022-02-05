//
//  main.cpp
//  正向的话要算除法，所以倒过来算
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        long long n = s.size(), val = 0, pk = 1;
        for (int i = 0; i < k; i++) {
            val = (val * power + s[n - 1 - i] - 'a' + 1) % mod;
        }
        for (int i = 0; i < k - 1; i++) pk = pk * power % mod;
        int res;
        for (int i = n - k; i >= 0; i--) {
            if (val == hashValue) res = i;
            if (i) {
                val = ((val - pk * (s[i + k - 1] - 'a' + 1) % mod) + mod) % mod;
                val = (val * power + s[i - 1] - 'a' + 1) % mod;
            }
        }
        return s.substr(res, k);
    }
};