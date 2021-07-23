//
//  main.cpp
//  题目描述的其实不是很清楚
//  其实，确定f确定的值的意思就是在试的过程中是最坏的可能。最坏的可能下，最小要多少次
//  用dp[i][j]表示在第i层有j+1个鸡蛋的结果
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int twoEggDrop(int n) {
        int dp[n + 10][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = i;
            dp[i][1] = i;
            for (int j = i; j >= 1; j--) {
                dp[i][1] = min(dp[i][1], max(dp[j - 1][0], dp[i - j][1]) + 1);
            }
        }
        return dp[n][1];
    }
};
