//
//  main.cpp
//  容易得到注释里的转移方程。
//  关键是去绝对值，分为k在j的左边还是右边可以分成两种情况
//  从而可以边遍历边计算在左边/右边的最大值，进行了优化
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        long long dp[m][n];
        //dp[i][j]=max{dp[i-1][k]+points[i][j]-abs(k-j)}
        for (int j = 0; j < n; j++) dp[0][j] = points[0][j];
        for (int i = 1; i < m; i++) {
            long long l, r;
            for (int j = 0; j < n; j++) {
                if (j == 0) l = dp[i - 1][0];
                else l = max(l, dp[i - 1][j] + j);
                dp[i][j] = l + points[i][j] - j;
            }
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) r = dp[i - 1][n - 1] - (n - 1);
                else r = max(r, dp[i - 1][j] - j);
                dp[i][j] = max(dp[i][j], r + points[i][j] + j);
            }
        }
        long long res = INT_MIN;
        for (int j = 0; j < n; j++) res = max(res, dp[m - 1][j]);
        return res;
    }
};
