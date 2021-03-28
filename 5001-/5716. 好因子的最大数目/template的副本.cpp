//
//  main.cpp
//  如果一个数分解为p1^q1 * p2^q2 * ..
//  要知道，好因子的个数，就是q1*q2*...qn
//  这道题就等价于整数拆分，拆成尽可能多个3，加个快速幂取模。也属于中等题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int qpow(int p, int q) {
        long long res = 1, tmp = p;
        while (q) {
            if (q & 1) res = (res * tmp) % mod;
            q >>= 1;
            tmp = (tmp * tmp) % mod;
        }
        return res % mod;
    }
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3) return primeFactors;
        if (primeFactors == 4) return 4;
        if (primeFactors == 5) return 6;
        if (primeFactors % 3 == 0) return qpow(3, primeFactors / 3);
        return (long long)qpow(3, primeFactors / 3 - 1) * maxNiceDivisors(primeFactors % 3 + 3) % mod;
    }
};
