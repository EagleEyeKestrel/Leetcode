//
//  main.cpp
//  O(n3)的做法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        //  dp[i][j]=arr[i][j]+min(arr[i-1][0])
        int n = arr.size(), res = INT_MAX;
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = arr[0][i];
            if (n == 1) res = min(res, dp[i]);
        }
        for (int i = 1; i < n; i++) {
            int tmp[n];
            for (int j = 0; j < n; j++) {
                tmp[j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    tmp[j] = min(tmp[j], dp[k] + arr[i][j]);
                }
                if (i == n - 1) res = min(res, tmp[j]);
            }
            memcpy(dp, tmp, n * sizeof(int));
        }
        return res;
    }
};
