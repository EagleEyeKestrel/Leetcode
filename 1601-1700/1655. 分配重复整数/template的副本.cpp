//
//  main.cpp
//  首先nums的顺序没有关系，只要计数就行
//  quantity很小，可以状压。用dp[i][mask]表示前i种数能否凑出quantity里的mask
//  穷举最后一种数去凑mask的子集sub即可。
//  注意计算sum的过程可以预处理。试了一下，预处理之后100+ms，不预处理要1000+
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int cnt[1010], a[60], dp[60][1024], sum[1024];
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        for (int x: nums) cnt[x]++;
        int n = 0, m = quantity.size();
        for (int val = 1; val <= 1000; val++) {
            if (cnt[val] > 0) {
                a[n++] = cnt[val];
            }
        }
        for (int mask = 0; mask < 1 << m; mask++) {
            for (int j = 0; j < m; j++) {
                if (mask >> j & 1) sum[mask] += quantity[j];
            }
        }
        for (int mask = 0; mask < 1 << m; mask++) {
            if (sum[mask] <= a[0]) dp[0][mask] = 1;
            else dp[0][mask] = 0;
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = 1;
            for (int mask = 1; mask < 1 << m; mask++) {
                dp[i][mask] = dp[i - 1][mask];
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    if (a[i] >= sum[sub]) {
                        dp[i][mask] |= dp[i - 1][mask ^ sub];
                    }
                    if (dp[i][mask]) break;
                }
            }
        }
        return dp[n - 1][(1 << m) - 1];
    }
};
