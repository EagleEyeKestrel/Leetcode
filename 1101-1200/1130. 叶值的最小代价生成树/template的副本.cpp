//
//  main.cpp
//  看上去花里胡哨的。其实就是注释里的递推式，预处理一下maxv即可，复杂度O(n3)
//  dp[i][j]表示i到j范围内的非叶值节点最小的和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        //dp[i][j]= dp[i][k]+dp[k+1][j]+max(i..k)*max(k+1..j)
        int n = arr.size();
        int dp[n][n], maxv[n][n];
        for (int i = 0; i < n; i++) {
            maxv[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxv[i][j] = max(maxv[i][j - 1], arr[j]);
            }
        }
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxv[i][k] * maxv[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
