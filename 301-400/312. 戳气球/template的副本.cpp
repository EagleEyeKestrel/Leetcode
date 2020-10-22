//
//  main.cpp
//  dp[i][j]表示从i到j的最大分数。从i到j关键在于，最后一个戳掉的是几
//  所以穷举最后一个戳掉的k，然后戳掉i到k-1以及k+1到j
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        for(int i = n; i >= 1; i--) {
            for(int j = i; j <= n; j++) {
                for(int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
