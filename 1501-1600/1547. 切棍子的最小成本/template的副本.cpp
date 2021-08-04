//
//  main.cpp
//  区间dp，递推方程见第20行。可以在cuts的头和尾加入0和n的坐标，方便计算
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        n = cuts.size();
        sort(cuts.begin(), cuts.end());
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
