//
//  main.cpp
//  比较简单的dp，用dp[i][j]表示nums1前i个元素 nums2前j个元素的结果
//  讨论是否要使用nums1[i]*nums[j]，但要注意
//  WA了一次，如果dp[i-1][j-1]<0，那完全可以省略不要
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int dp[m][n];
        dp[0][0] = nums1[0] * nums2[0];
        for (int j = 1; j < n; j++) dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
        for (int i = 1; i < m; i++) dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(nums1[i] * nums2[j] + max(0, dp[i - 1][j - 1]), max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[m - 1][n - 1];
    }
};
