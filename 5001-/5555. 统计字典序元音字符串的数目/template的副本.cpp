//
//  main.cpp
//  比较简单的dp，第一维表示长度，第二位表示末尾单词，每次只能加前面一位末尾单词更小的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n + 1][5];
        for(int j = 0; j < 5; j++) dp[1][j] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j] = 0;
                for(int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        return dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4];
    }
};
