//
//  main.cpp
//  属于比较容易的困难题。计算每个数字作为最大数/最小数出现的次数，然后累计
//  这里用的是快速幂。当然也有更好的方法，因为这个次数可以在遍历的过程中累乘，不一定要每次都算一遍
//  Copyright © 2020 ji luyang. All rights reserved.
//
class Solution {
public:
    int mod = 1e9 + 7;
    long qpow(long x, long p) {
        long res = 1;
        while(p) {
            if(p % 2) res = (res * x) % mod;
            x = (x * x) % mod;
            p >>= 1;
        }
        return res % mod;
    }
    int sumSubseqWidths(vector<int>& A) {
        long n = A.size(), res = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i <= n; i++) {
            long asBig = qpow(2, i - 1);
            long asSmall = qpow(2, n - i);
            res = (res + (asBig - asSmall) * A[i - 1]) % mod;
        }
        return (res + mod) % mod;
    }
};
