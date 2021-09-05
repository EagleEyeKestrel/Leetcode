//
//  main.cpp
//  dp[i][j]表示前i个元素 调整j次大小 最小浪费代价
//  穷举最后一次调整是在k...i，递推方程在注释中，最后一段应该调整为k...i的最大值
//  所以还需要预处理一下区间最大值，以及前缀和，复杂度O(n3)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        //dp[i][j] = dp[k-1][j-1]+max[k][i] * (i-k+1)-s[k...i]
        int s[n];
        s[0] = nums[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + nums[i];
        int maxv[n][n];
        for (int i = 0; i < n; i++) maxv[i][i] = nums[i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                maxv[i][j] = max(nums[i], maxv[i + 1][j]);
            }
        }
        int dp[n][k + 1];
        for (int i = 0; i < n; i++) dp[i][0] = maxv[0][i] * (i + 1) - s[i];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= min(k, i); j++) {
                dp[i][j] = INT_MAX;
                for (int l = i; l >= j; l--) {
                    dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + maxv[l][i] * (i - l + 1) - s[i] + s[l - 1]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
