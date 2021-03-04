//
//  main.cpp
//  开始把题目看错了，实际上很简单
//  dp[i]表示0-i的结果，j表示最后一段子数组的长度，复杂度O(nk)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int nowmax = arr[i];
            for (int j = 1; j <= k && j <= i + 1; j++) {
                nowmax = max(nowmax, arr[i - j + 1]);
                dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + nowmax * j);
            }
        }
        return dp[n - 1];
    }
};
