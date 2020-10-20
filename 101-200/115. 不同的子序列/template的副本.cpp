//
//  main.cpp
//  dp[i][j]表示t前j个字符出现在s前i个字符的次数
//  如果s[i-1]==t[j-1]那么t[j-1]就可以放在s[i-1]的位置，对应dp[i-1][j-1]
//  当然也可以放在之前，对应dp[i-1][j]
//  如果不等，那么就只能放在之前
//  另外。。题目还强调了一下不超过int,结果还是需要long
//  另外的另外，空间显然可以优化到O(n)，这里就没写了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        long dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++) {
            dp[i][0] = 1;
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};
