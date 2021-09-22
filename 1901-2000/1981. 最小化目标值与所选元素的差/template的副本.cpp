//
//  main.cpp
//  想了一会儿。用dp[i][val]表示前i行 是否能凑到和j
//  注意这里不需要dp[i][j][val]，不需要保存每个列的信息
//  对于dp[i][val]，穷举每一列看看能否凑到即可，复杂度(70*1600*70)
//  这里有两个优化，否则容易超时
//  一个是dp只开到target*2+1，而非1600，开多了会超时。。
//  另外，在循环的时候 val写在j外层，这样可以break掉，有不少优化
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int dp[70][2 * target + 1];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; j++) if (mat[0][j] <= 2 * target) dp[0][mat[0][j]] = 1;
        for (int i = 1; i < m; i++) {
            for (int val = 1; val <= 2 * target; val++) {
                for (int j = 0; j < n; j++) {
                    if (val - mat[i][j] > 0 && dp[i - 1][val - mat[i][j]]) {
                        dp[i][val] = 1;
                        break;
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i <= 2 * target; i++) {
            if (dp[m - 1][i]) res = min(res, abs(i - target));
        }
        if (res == INT_MAX) {
            int minsum = 0;
            for (int i = 0; i < m; i++) {
                int val = 100;
                for (int j = 0; j < n; j++) {
                    val = min(val, mat[i][j]);
                }
                minsum += val;
            }
            res = abs(target - minsum);
        }
        return res;
    }
};
