//
//  main.cpp
//  和丑数类似，只不过这里要遍历一下primes列表，用id数组表示每个质因数对应的相乘位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        int res[n], id[m];
        res[0] = 1;
        memset(id, 0, sizeof(id));
        for (int i = 1; i < n; i++) {
            int minv = INT_MAX;
            for (int j = 0; j < m; j++) {
                minv = min(minv, primes[j] * res[id[j]]);
            }
            res[i] = minv;
            for (int j = 0; j < m; j++) {
                if (minv == primes[j] * res[id[j]]) id[j]++;
            }
        }
        return res[n - 1];
    }
};
