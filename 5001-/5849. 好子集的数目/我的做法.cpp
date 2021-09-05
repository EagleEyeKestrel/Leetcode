//
//  main.cpp
//  我的做法，比较烦。预处理出每个数的因子factors
//  然后由于2的倍数只能有一个，穷举2的倍数是哪个。对剩余的所有11个数直接状压
//  主要过程是判断能否共存。结果时间卡得很紧，11次方的话大概要1000+ms
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
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
        long long n = nums.size(), res = 0;
        int f[31][31];
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> factors[31];
        int bad[31] = {0};
        bad[4] = bad[8] = bad[9] = bad[12] = bad[16] = bad[18] = bad[20] = bad[24] = bad[25] = bad[27] = bad[28] = 1;
        for (int i = 2; i <= 30; i++) {
            int tmp = i;
            for (int x: primes) {
                if (tmp % x == 0) {
                    factors[i].push_back(x);
                    while (tmp % x == 0) tmp /= x;
                }
            }
        }

        int cnt[31];
        memset(cnt, 0, sizeof(cnt));
        for (int x: nums) cnt[x]++;
        int a[11] = {3, 5, 7, 11, 13, 15, 17, 19, 21, 23, 29};
        for (int x = 0; x <= 30; x += 2) {
            if (x && cnt[x] == 0) continue;
            if (bad[x]) continue;
            for (int mask = 0; mask < 1 << 11; mask++) {
                int flag = 1;
                vector<int> others;
                for (int i = 0; i < 11; i++) {
                    if (mask >> i & 1) {
                        if (bad[a[i]]) {
                            flag = 0;
                            break;
                        }
                        others.push_back(a[i]);
                    }
                }
                if (!flag) continue;
                if (x) others.push_back(x);
                if (others.empty()) continue;
                int vis[31] = {0};
                for (int o: others) {
                    for (int p: factors[o]) {
                        if (vis[p]) {
                            flag = 0;
                            break;
                        }
                        vis[p] = 1;
                    }
                    if (flag == 0) break;
                }
                if (!flag) continue;
                long long tmp = 1;
                for (int o: others) tmp = (tmp * cnt[o]) % mod;
                res = (res + tmp) % mod;
            }
        }
        if (cnt[1]) res = (res * qpow(2, cnt[1])) % mod;
        return res;
    }
};
