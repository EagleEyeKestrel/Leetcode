//
//  main.cpp
//  法儿。考虑dp[i][j-k],dp[i-1][k-1]两条线
//  发现随j递增之后，dp[i][j-k]只会上移而dp[i-1][k-1]不变，所以交点也只会上移
//  所以设交点为pos，不断更新pos即可。复杂度O(nk)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int superEggDrop(int k, int n) {
        //dp[i][j]=min{max(dp[i][j-k], dp[i-1][k-1])+1}, 1<=k<=j
        int dp[k + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++) dp[1][j] = j;
        for (int i = 2; i <= k; i++) {
            int pos = 1;
            for (int j = 1; j <= n; j++) {
                while (dp[i][j - pos] > dp[i - 1][pos - 1]) pos++;
                dp[i][j] = max(dp[i][j - pos], dp[i - 1][pos - 1]) + 1;
            }
        }
        return dp[k][n];
    }
};
