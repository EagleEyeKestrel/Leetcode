//
//  main.cpp
//  不是很难的困难题，只要优化掉一个维度就可以了
//  s[i][j]表示第i行的前j列和，然后穷举两列，用一个集合存已经出现过的矩形和，这样就会出现一层log复杂度
//  可以通过判断m和n谁大，来优化枚举策略，让更大的一层出现在log
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = matrix[i - 1][j - 1] + s[i][j - 1];
            }
        }
        int res = -1e7;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int sum = 0;
                set<int> se;
                se.insert(0);
                for (int i = 1; i <= m; i++) {
                    sum += s[i][r] - s[i][l - 1];
                    auto it = se.lower_bound(sum - k);
                    if (it != se.end() && sum - *it > res) {
                        res = sum - *it;
                    }
                    se.insert(sum);
                }
            }
        }
        return res;
    }
};
