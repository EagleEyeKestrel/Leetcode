//
//  main.cpp
//  dp。 用dp[i]表示当前有i分，最后不超过N的概率
//  dp[i] = 1/W(dp[i+1]+dp[i+2]+...+dp[i+W])。其中后面的和用一个变量s维护
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double new21Game(int N, int K, int W) {
        double dp[N + W];
        for(int i = N + 1; i < N + W; i++) dp[i] = 0;
        for(int i = K; i <= N; i++) dp[i] = 1;
        double s = 0;
        for(int i = K; i < K + W; i++) s += dp[i];
        for(int i = K - 1; i >= 0; i--) {
            dp[i] = s / W;
            s = s + dp[i] - dp[i + W];
        }
        return dp[0];
    }
};
