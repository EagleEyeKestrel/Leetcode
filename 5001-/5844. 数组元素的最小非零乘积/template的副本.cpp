//
//  main.cpp
//  结果可以猜想是(2^p - 1) * (2^p - 2)^{2^{p-1}-1}
//  要注意。之前从来没遇到过指数还要取模的情况，要注意指数的取模应该是对mod-1取模
//  和加减乘除不一样
//  具体为什么结果是这个，可以去看看题解
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int qpow(long long a, long long b, int MOD) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    int minNonZeroProduct(int p) {
        long long res = (qpow(2, p, mod) - 1 + mod) % mod;
        long long t = (res - 1 + mod) % mod;
        t = qpow(t, (qpow(2, p - 1, mod - 1) - 1 + mod - 1) % (mod - 1), mod);
        return res * t % mod;
    }
};
