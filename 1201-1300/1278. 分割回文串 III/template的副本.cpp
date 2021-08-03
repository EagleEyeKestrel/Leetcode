//
//  main.cpp
//  有n3k的做法，也就是用dp[i][j][k]表示将区间[i,j]划分成k个部分所需的次数
//  但其实不需要。减少1维，用dp[i][j]表示将[0,i]分割成j部分需要的次数
//  dp[i][j]=min{dp[l][j-1]+cost[l+1][i]}
//  其中cost[l][r]表示将[l,r]变成回文需要的次数。预处理出来，复杂度就是n2k
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        //dp[i][j] = dp[l][j-1]+cost(l+1,i)
        int dp[n][k + 1], cost[n][n];
        memset(cost, 0, sizeof(cost));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    cost[i][j] = cost[i + 1][j - 1];
                } else {
                    cost[i][j] = 1 + cost[i + 1][j - 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= k && j <= i + 1; j++) {
                dp[i][j] = INT_MAX;
                for (int l = j - 2; l <= i - 1; l++) {
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
