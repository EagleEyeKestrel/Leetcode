//
//  main.cpp
//  状压，dp[i][mask]表示前i+1个工人完成工作集合mask需要的最小时间
//  对于dp[i][mask]，计算第i+1个工人做的工作集合subset，那么前i个工人的时间是dp[i-1][mask^subset]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int sum[4100], dp[12][4100];
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        memset(sum, 0, sizeof(sum));
        for (int mask = 0; mask < (1 << n); mask++) {
            int tmp = 0;
            for (int j = 0; j < 15; j++) {
                if ((mask >> j) & 1) {
                    tmp += jobs[j];
                }
            }
            sum[mask] = tmp;
        }

        for (int i = 0; i < k; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                if (i == 0) {
                    dp[i][mask] = sum[mask];
                    continue;
                }
                dp[i][mask] = sum[mask];
                for (int subset = mask; subset; subset = (subset - 1) & mask) {
                    dp[i][mask] = min(dp[i][mask], max(dp[i - 1][mask ^ subset], sum[subset]));
                }
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};
