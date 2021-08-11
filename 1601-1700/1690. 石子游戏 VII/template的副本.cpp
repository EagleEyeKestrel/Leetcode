//
//  main.cpp
//  典型的博弈型dp
//  dp[i][j]表示i到j范围内，先手最多能领先多少分？
//  分两种情况，拿前一个元素或者后一个
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + stones[i - 1];
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j <= n; j++) {
                dp[i][j] = max(s[j] - s[i] - dp[i + 1][j], s[j - 1] - s[i - 1] - dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
