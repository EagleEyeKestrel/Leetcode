//
//  main.cpp
//  比较更正统的状压的话，可以发现每个积肯定可以表示成30以下素数的积。而且每个素数不超过1个
//  而30以下的素数刚好是10个。所以可以用1024以下的数来表示一个积
//  先预处理出nums中所有的mask数量。然后用dp方程
//  dp[mask|j]+=dp[mask]*cnt[j]，即对于一组素数p1 p2 .. pk的积，只会记一次，记在最大的素数上
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    long long cnt[1024],dp[1024];
    int qpow(long long a, int b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        for (int num: nums) {
            int mask = 0;
            for (int i = 0; i < 10; i++) {
                if (num % p[i] == 0) {
                    mask |= (1 << i);
                    num /= p[i];
                }
                if (num % p[i] == 0) {
                    mask = -1;
                    break;
                }
            }
            if (mask != -1) cnt[mask]++;
        }
        dp[0] = qpow(2, cnt[0]);
        for (int mask = 0; mask < 1024; mask++) {
            if (dp[mask] == 0) continue;
            for (int j = mask + 1; j < 1024; j++) {
                if (cnt[j] == 0 || (mask & j)) continue;
                dp[mask | j] = (dp[mask | j] + dp[mask] * cnt[j] % mod) % mod;
            }
        }
        long long res = 0;
        for (int mask = 1; mask < 1024; mask++) res = (res + dp[mask]) % mod;
        return res;
    }
};
