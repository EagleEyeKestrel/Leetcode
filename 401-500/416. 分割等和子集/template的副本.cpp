//
//  main.cpp
//  经典的背包问题，空间优化成一维
//  dp[i][j]表示前i个，和不超过j的最大和是多少
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    //dp[i][j] = max dp[i - 1][j] dp[i-1][j-nums[i]]
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int num: nums) sum += num;
        if(sum % 2) return false;
        int dp[sum / 2 + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int j = sum / 2; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
};
