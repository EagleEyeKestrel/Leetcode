//
//  main.cpp
//  二维前缀和，全部把矩阵的数字放到a里，然后排序即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), now = 0;
        int a[m * n];
        int dp[m][n];
        dp[0][0] = matrix[0][0];
        a[now++] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
            a[now++] = dp[i][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] ^ matrix[0][i];
            a[now++] = dp[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = matrix[i][j] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                a[now++] = dp[i][j];
            }
        }
        sort(a, a + now, greater<int>());
        return a[k - 1];
    }
};
