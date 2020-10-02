//
//  main.cpp
//  思想简单的，dp[i][j]表示从i~j范围内确保猜出来的最少花费
//  最难理解的是这个 ”确保“和最少花费
//  确保的意思是，过程最曲折，也就是我猜一个数，答案会尽量不是我猜的数，而且在花费更大的区间里
//  最少花费的是，我每次猜的数 j, 要是这么多数里确保猜中的花费最少的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        for(int k = 2; k <= n; k++) {
            for(int i = 1; i <= n - k + 1; i++) {
                //dp[i][i + k -1]
                int minv = INT_MAX;
                for(int j = i; j <= i + k - 1; j++) {
                    minv = min(minv, max(dp[i][j - 1], dp[j + 1][i + k - 1]) + j);
                }
                dp[i][i + k - 1] = minv;
            }
        }
        return dp[1][n];
    }
};
