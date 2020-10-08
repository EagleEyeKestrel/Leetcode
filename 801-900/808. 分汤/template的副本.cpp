//
//  main.cpp
//  看上去是简单的dp，但其实并不容易
//  dp[i][j]表示剩余A和B的量，但是为了简化计算，看到每次分的都是25的倍数，将N除以25，向上取整
//  然后初始化，每次有1/4的概率去往四种状态
//  注意N的范围很大，当N很大的时候，概率无限逼近于1，所以直接返回1即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double soupServings(int N) {
        if(N >= 5000) return 1;
        int n = N % 25 ? N / 25 + 1 : N / 25;
        double dp[n + 1][n + 1];
        dp[0][0] = 0.5;
        for(int i = 1; i <= n; i++) dp[i][0] = 0;
        for(int j = 1; j <= n; j++) dp[0][j] = 1;
        for(int i = 1; i <= n; i++) {
            int a1 = i >= 4 ? i - 4 : 0;
            int a2 = i >= 3 ? i - 3 : 0;
            int a3 = i >= 2 ? i - 2 : 0;
            int a4 = i >= 1 ? i - 1 : 0;
            for(int j = 1; j <= n; j++) {
                int b1 = j;
                int b2 = j >= 1 ? j - 1 : 0;
                int b3 = j >= 2 ? j - 2 : 0;
                int b4 = j >= 3 ? j - 3 : 0;
                dp[i][j] = (dp[a1][b1] + dp[a2][b2] + dp[a3][b3] + dp[a4][b4]) / 4;
            }
        }
        return dp[n][n];
    }
};
