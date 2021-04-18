//
//  main.cpp
//  最基础的dp，用一个滚动数组。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), res = INT_MAX;
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
            if (n == 1) res = min(res, dp[i]);
        }
        for (int i = 1; i < n; i++) {
            int tmp[n];
            for (int j = 0; j < n; j++) {
                tmp[j] = dp[j] + matrix[i][j];
                if (j) tmp[j] = min(tmp[j], dp[j - 1] + matrix[i][j]);
                if (j < n - 1) tmp[j] = min(tmp[j], dp[j + 1] + matrix[i][j]);
                if (i == n - 1) res = min(res, tmp[j]);
            }
            memcpy(dp, tmp, n * sizeof(int));
        }
        return res;
    }
};
