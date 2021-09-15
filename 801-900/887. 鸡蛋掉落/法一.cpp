//
//  main.cpp
//  非常经典的dp题。
//  用dp[i][j]表示i个鸡蛋测j层楼，穷举鸡蛋放的高度k。
//  画个图像可以发现单调性，从而采用二分搜索查找dp[i][j-k]=dp[i-1][k-1]的点
//  复杂度O(nklogn)
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
            for (int j = 1; j <= n; j++) {
                int l = 1, r = j;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (dp[i - 1][mid - 1] < dp[i][j - mid]) l = mid + 1;
                    else r = mid;
                }
                dp[i][j] = max(dp[i][j - l], dp[i - 1][l - 1]) + 1;
            }
        }
        return dp[k][n];
    }
};
