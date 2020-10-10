//
//  main.cpp
//  dp[i][j]表示从i到j的多边形最小得分
//  每次剖分的时候设i到j的边是和mid去组成三角形，穷举mid，复杂度O(n3)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int k = 2; k < n; k++) {
            for(int i = 0; i + k < n; i++) {
                dp[i][i + k] = 1 << 30;
                for(int mid = i + 1; mid < i + k; mid++) {
                    dp[i][i + k] = min(dp[i][i + k], dp[i][mid] + dp[mid][i + k] + A[i] * A[i + k] * A[mid]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
