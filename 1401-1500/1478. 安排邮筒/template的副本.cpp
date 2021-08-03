//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/106741013?spm=1001.2014.3001.5501
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        int dis[n][n], dp[n][k + 1];
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dis[i][j] = dis[i][j - 1] + abs(houses[j] - houses[(i + j) / 2]);
            }
        }
        for (int i = 0; i < n; i++) dp[i][1] = dis[0][i];
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= min(k, i + 1); j++) {
                dp[i][j] = INT_MAX;
                for (int kk = i; kk >= j - 1; kk--) {
                    dp[i][j] = min(dp[i][j], dp[kk - 1][j - 1] + dis[kk][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
