//
//  main.cpp
//  比较简单的dp，按结束时间排序后，dp[i]=max(dp[0],dp[1]...dp[id]) + cost(i)
//  id是结束时间不超过rides[i][0]的最大索引。维护前面的最大值即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](auto &x, auto &y) {
            if (x[1] == y[1]) return x[0] < y[0];
            return x[1] < y[1];
        });
        int m = rides.size();
        long long dp[m], maxv[m], end[m];
        for (int i = 0; i < m; i++) end[i] = rides[i][1];
        dp[0] = rides[0][1] - rides[0][0] + rides[0][2];
        maxv[0] = dp[0];
        for (int i = 1; i < m; i++) {
            dp[i] = dp[i - 1];
            int id = upper_bound(end, end + i, rides[i][0]) - end - 1;
            if (id < 0) {
                dp[i] = max(dp[i], (long long)rides[i][1] - rides[i][0] + rides[i][2]);
                maxv[i] = max(maxv[i - 1], dp[i]);
                continue;
            }
            dp[i] = max(dp[i], maxv[id] + rides[i][1] - rides[i][0] + rides[i][2]);
            maxv[i] = max(maxv[i - 1], dp[i]);
        }
        return dp[m - 1];
    }
};
