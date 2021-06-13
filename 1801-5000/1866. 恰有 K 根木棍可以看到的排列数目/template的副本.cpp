//
//  main.cpp
//  大概是做过的最简单的周赛最后一题了
//  对于n个木棍，最后一根木棍如果是最长的，那么一定能看见，所以还需要dp[n-1][k-1]
//  如果不是最长的，那肯定看不见，所以有n-1种取法，前面还剩下dp[n-1][k]
//  要注意两点，第一，考虑到dp[n-1][k]里，可能会出现i<j的情况
//  这种情况对应为0，所以要先memset一下，不然可能是随机值
//  第二点，写死前两项的时候，要注意k的范围。满以为肯定不会WA，结果因为开始写的是k+1，然而写死了dp[2][2]，WA了。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int rearrangeSticks(int n, int k) {
        //dp[n][k] = dp[n-1][k-1] + (n-1)*dp[n-1][k];
        int dp[n + 1][k + 10];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        dp[2][1] = 1; dp[2][2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= min(k, i); j++) {
                dp[i][j] = (dp[i - 1][j - 1] + (long long)(i - 1) * dp[i - 1][j]) % mod;
            }
        }
        return dp[n][k];
    }
};
