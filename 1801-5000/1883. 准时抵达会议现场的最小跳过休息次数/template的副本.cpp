//
//  main.cpp
//  dp的题
//  用dp[i][j]表示前i个路段，最多跳j次，所需要的最短时间
//  递推公式在注释里，讨论最后一次跳or不跳即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        double sum = 0;
        for (int x: dist) sum += x;
        if (sum / speed > hoursBefore) return -1;
        //dp[i][j]=min(dp[i-1][j]+t1, dp[i-1][j-1]+t2)
        double dp[n][n + 1];
        dp[0][0] = dist[0] / speed + (dist[0] % speed != 0);
        dp[0][1] = (double)dist[0] / speed;
        for (int j = 2; j <= n; j++) dp[0][j] = dp[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i + 1; j++) {
                dp[i][j] = dp[i - 1][j] + (double)dist[i] / speed;
                if (abs(dp[i][j] - (int)dp[i][j]) > 1e-6) dp[i][j] = (int)dp[i][j] + 1;
                if (j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (double)dist[i] / speed);
            }
            for (int j = i + 2; j <= n; j++) dp[i][j] = dp[i][i];
        }
        for (int j = 0; j <= n; j++) if (dp[n - 1][j] <= hoursBefore) return j;
        return -1;
    }
};
