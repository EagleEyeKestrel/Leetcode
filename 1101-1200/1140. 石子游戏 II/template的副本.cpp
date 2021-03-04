//
//  main.cpp
//  用dp[i][j]表示，从i到piles末尾，并且M是j的情况，先手能获得的最大分差
//  穷举拿的石子数量k，处理一下前缀和，可以获得这k个石子的分数减去剩余的dp值
//  复杂度O(n3)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int dp[n + 1][110];
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= 100; j++) dp[n][j] = piles[n - 1];
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + piles[i - 1];
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 100; j >= 1; j--) {
                dp[i][j] = INT_MIN;
                for (int k = 1; k <= 2 * j && n - i + 1 >= k; k++) {
                    dp[i][j] = max(dp[i][j], s[i + k - 1] - s[i - 1] - (i + k <= n ? dp[i + k][max(j, k)] : 0));
                }
            }
        }
        return (s[n] + dp[1][1]) / 2;
    }
};
