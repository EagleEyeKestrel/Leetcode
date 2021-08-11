//
//  main.cpp
//  关键在于每个歌都要放一遍，开始不知道怎么处理，然后想出来了
//  用dp[i][j]表示前i+1个歌 总共j种 有多少种方案
//  如果i+1首歌是新的一种 那就是dp[i-1][j-1] 然后新的歌有n-j+1种
//  如果不是新的一种 那前i个也是j种。另外不能和前k个重复，所以第i+1个有j-k种
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numMusicPlaylists(int n, int L, int k) {
        int dp[L][n + 1];
        int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][1] = n;
        for (int i = 1; i < L; i++) {
            for (int j = 1; j <= min(i + 1, n); j++) {
                if (j) {
                    dp[i][j] = (dp[i][j] + (long long)dp[i - 1][j - 1] * (n - j + 1) % mod) % mod;
                }
                if (j >= k) {
                    dp[i][j] = (dp[i][j] + (long long)dp[i - 1][j] * (j - k) % mod) % mod;
                }
            }
        }
        return dp[L - 1][n];
    }
};
