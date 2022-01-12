//
//  main.cpp
//  比较普通的dp
//  比如对于正金字塔，有dp[i][j]=min(l[i][j], r[i][j], dp[i-1][j]+1)
//  其中l r表示左/右连续1的个数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int l[m][n], r[m][n];
        for (int i = 0; i < m; i++) {
            l[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) l[i][j] = l[i][j - 1] + 1;
                else l[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            r[i][n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                if (grid[i][j] == 1) r[i][j] = r[i][j + 1] + 1;
                else r[i][j] = 0;
            }
        }
        int dp[m][n], dp2[m][n];
        for (int j = 0; j < n; j++) dp[0][j] = grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val1 = l[i][j], val2 = r[i][j], val3 = dp[i - 1][j];
                dp[i][j] = min(min(val1, val2), val3 + 1);
            }
        }
        for (int j = 0; j < n; j++) dp2[m - 1][j] = grid[m - 1][j];
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int val1 = l[i][j], val2 = r[i][j], val3 = dp2[i + 1][j];
                dp2[i][j] = min(min(val1, val2), val3 + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > 1) res += dp[i][j] - 1;
                if (dp2[i][j] > 1) res += dp2[i][j] - 1;
            }
        }
        return res;
    }
};
