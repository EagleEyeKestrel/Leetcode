//
//  main.cpp
//  dp，如果S[i]!=S[j]，那么显然两端不能同时取
//  关键是相等的时候怎么算
//  a ... a ...a... a 找到i往右以及j往左的第一个相等的位置
//  第一种情况，a....a 中间没有相等，那就是dp[i+1][j-1](下面用x替代), 加上axa，再加上aa和a，所以是2x+2种
//  第二种情况，a...a...a，中间只有一个a，那么包括x，axa，再加上aa，所以是2x+1
//  第三种情况，a...a..a...a，设最近的两个a索引是l和r
//  x axa，另外dp[l+1][r-1]部分的子串本来就有a包围，所以要减去这个重复部分
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (S[i] != S[j]) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                } else {
                    int l = i + 1, r = j - 1;
                    while (l <= j && S[l] != S[i]) l++;
                    while (r >= i && S[r] != S[j]) r--;
                    if (l > r) dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    else if(l == r) dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    else dp[i][j] = 2 * dp[i + 1][j - 1] - dp[l + 1][r - 1];
                }
                dp[i][j] = (dp[i][j] % mod + mod) % mod;
            }
        }
        return dp[0][n - 1];
    }
};
