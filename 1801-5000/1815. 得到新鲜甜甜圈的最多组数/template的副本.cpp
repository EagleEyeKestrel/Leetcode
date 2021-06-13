//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/115446512
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dp[1111111];
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        int cnt[batchSize];
        memset(cnt, 0, sizeof(cnt));
        for (int group: groups) {
            cnt[group % batchSize]++;
        }
        int sz = 1;
        int w[11];
        w[0] = 1;
        for (int i = 0; i < batchSize; i++) {
            w[i + 1] = w[i] * (cnt[i] + 1);
            sz *= (cnt[i] + 1);
        }
        dp[0] = 0;
        for (int mask = 1; mask < sz; mask++) {
            dp[mask] = 0;
            int tmp = mask, sum = 0;
            int v[10];
            memset(v, 0, sizeof(v));
            for (int b = 0; b < batchSize; b++) {
                if (!cnt[b]) continue;
                int x = tmp % (cnt[b] + 1);
                v[b] = x;
                sum = (sum + x * b) % batchSize;
                tmp /= (cnt[b] + 1);
            }
            for (int b = 0; b < batchSize; b++) {
                if (v[b]) {
                    int last = (sum - b + batchSize) % batchSize;
                    dp[mask] = max(dp[mask], dp[mask - w[b]] + (last == 0));
                }
            }
        }
        return dp[sz - 1];
    }
};
