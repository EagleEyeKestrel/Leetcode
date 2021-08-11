//
//  main.cpp
//  题目本身不难，对网格中所有数进行排序，然后从高到低进行dp递推
//  v中存的是网格编号按数字大小的排序。
//  有一个易错点！23行的判断是必要的。否则 直接+1 -1可能会跑到下一行/上一行的某个点，就不对了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> v;
        for (int i = 0; i < m * n; i++) v.push_back(i);
        sort(v.begin(), v.end(), [&](int x, int y) {
            return matrix[x / n][x % n] < matrix[y / n][y % n];
        });
        int dp[m * n];
        int d[4] = {-1, 1, -n, n};
        for (int i = m * n - 1; i >= 0; i--) {
            dp[v[i]] = 1;
            for (int k = 0; k < 4; k++) {
                if (k == 0 && v[i] % n == 0 || k == 1 && v[i] % n == n - 1) continue;
                int j = v[i] + d[k];
                if (j < 0 || j >= m * n || matrix[j / n][j % n] <= matrix[v[i] / n][v[i] % n]) continue;
                dp[v[i]] = max(dp[v[i]], dp[j] + 1);
            }
        }
        for (int i = 0; i < m * n; i++) res = max(res, dp[i]);
        return res;
    }
};
