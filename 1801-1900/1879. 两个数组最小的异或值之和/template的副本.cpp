//
//  main.cpp
//  大概是最简单的最后一题了
//  据说一直对nums2调用next_permutation会超时
//  所以采用状压，穷举采用nums2的哪些元素
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int dp[1 << n];
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            dp[mask] = INT_MAX;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    int tmp = dp[mask ^ (1 << i)] + (nums1[__builtin_popcount(mask) - 1] ^ nums2[i]);
                    dp[mask] = min(dp[mask], tmp);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
