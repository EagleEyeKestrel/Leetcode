//
//  main.cpp
//  比较基础的dp，用dp[i]表示 面临从i到n-1这么多石头的时候，最多能比对面赢多少分
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[n + 1];
        dp[n] = 0;
        dp[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            if (i <= n - 3) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
