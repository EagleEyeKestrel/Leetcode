//
//  main.cpp
//  很简单的dp，dp[i]表示还有i 个石头，先手会不会赢，复杂度(n根号n)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j * j <= i; j++) {
                if (dp[i - j * j] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n] == 1;
    }
};
