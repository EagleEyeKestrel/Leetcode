//
//  main.cpp
//  更快的方法。dp[i][j]表示i此操作，j个鸡蛋，最多能确定多少高度
//  我们扔了一个鸡蛋。如果没碎，那么上面我们可以确定dp[i][j-1]高度
//  如果碎了，下面我们可以确定dp[i-1][j-1]高度。
//  所以我们要在dp[i-1][j-1]+1的地方扔，并且dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+1
//  找到大于等于n的最小的i，使得dp[i][k]>=n即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int superEggDrop(int k, int n) {
        //dp[i][j]=dp[i-1][j]+1+dp[i-1][j-1];
        int dp[n + 1][k + 1];
        int i = 0;
        memset(dp, 0, sizeof(dp));
        while (dp[i][k] < n) {
            i++;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j] + 1 + dp[i - 1][j - 1];
            }
        }
        return i;
    }
};
