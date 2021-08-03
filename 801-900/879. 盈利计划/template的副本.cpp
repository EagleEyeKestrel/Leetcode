//
//  main.cpp
//  dp[i][j][k]表示i个人，从group[0]到group[j]，取得至少k的利润 有多少种
//  递推方程见注释那行。要么取group[j]，要么不取
//  关键是边界条件的处理，这里着重处理了0个人 以及第一个任务的情况。注意21行要考虑k=0的情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7, m = group.size();
        int dp[n + 1][m][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < m; j++) dp[0][j][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    //dp[i][j][k]=dp[i-group[j]][j-1][k-profit[j]]+dp[i][j-1][k];
                    if (j == 0) {
                        if (k == 0) dp[i][j][k]++;
                        if (i >= group[j] && profit[j] >= k) {
                            dp[i][j][k]++;
                        }
                        continue;
                    }
                    dp[i][j][k] = dp[i][j - 1][k];
                    if (i < group[j]) continue;
                    dp[i][j][k] = (dp[i][j][k] + dp[i - group[j]][j - 1][max(k - profit[j], 0)]) % mod;
                }
            }
        }
        return dp[n][m - 1][minProfit];
    }
};
