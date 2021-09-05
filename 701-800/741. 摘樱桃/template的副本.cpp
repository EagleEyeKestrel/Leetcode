//
//  main.cpp
//  dp[i][p]表示 走k步时，两条路都看作从（0,0)出发，分别到达(i,k-i) (p,k-p)时的最大收益
//  空间优化到二维，时间是O(n3)的
//  要注意。第一个长if里，要给dp[i][p]=-1再continue。因为在上一个k里这个状态可能是合法的
//  另外，第二个continue也是不可或缺的。只有状态能达到，才需要加上是否是樱桃的属性。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n];
        //dp[step][i][p]=max{dp[step-1][i -1?][p -1?]}
        memset(dp, -1, sizeof(dp));
        dp[0][0] = grid[0][0];
        for (int k = 1; k <= 2 * n - 2; k++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int p = n - 1; p >= 0; p--) {
                    int j = k - i, q = k - p;
                    if (j < 0 || q < 0 || j >= n || q >= n || grid[i][j] == -1 || grid[p][q] == -1) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] == -1) continue;
                    if (grid[i][j] == 1) dp[i][p]++;
                    if (i != p && grid[p][q] == 1) dp[i][p]++;
                }
            }
        }
        return max(0, dp[n - 1][n - 1]);
    }
};
