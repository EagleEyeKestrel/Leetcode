//
//  main.cpp
//  最综合的情况了。dp[i][j][k]，表示前i天，已经完成最多j次交易，k表示是否持有股票
//  要先讨论k很大的情况，等价于可以无限次交易，然后不难写出转移方程。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n / 2) {
            int res = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        int dp[n + 1][k + 1][2];
        for(int j = 0; j <= k; j++) {
            dp[0][j][0] = 0;
            dp[0][j][1] =INT_MIN;
        }
        for(int i = 1; i <= n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], -prices[i - 1]);
            for(int j = 1; j <= k; j++) {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i - 1]);
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i - 1]);
            }
        }
        return dp[n][k][0];
    }
};
