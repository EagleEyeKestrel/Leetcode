//
//  main.cpp
//  发现之前其实没有彻底理解这个dp，比如如果把dp[i][j]初始化为dp[i][j-1]+1就会不对
//  因为这里的讨论标准是,s[i]是单独打印的还是和其他字符一起打印的
//  如果单独打印那就是dp[i+1][j]+1
//  否则就要穷举它的末端k在哪里
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
