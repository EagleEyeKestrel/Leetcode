//
//  main.cpp
//  看上去难，实际上就是偶数位有五种，奇数位有四种情况。
//  甚至不需要考虑第一位不为0的情况。只是需要掌握一个快速幂
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    long long qpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            b >>= 1;
            a = (a * a) % mod;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long res = qpow(5, n / 2 + (n & 1));
        res = res * qpow(4, n / 2) % mod;
        return res;
    }
};
