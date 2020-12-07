//
//  main.cpp
//  从i-1推i。这个f可以用__builtin_popcount代替
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int x) {
        int res = 0;
        while(x) {
            x >>= 1;
            res++;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        int res = 1;
        for(int i = 2; i <= n; i++) {
            res = ((long long)res * (long long)pow(2, f(i)) + i) % mod;
        }
        return res;
    }
};
