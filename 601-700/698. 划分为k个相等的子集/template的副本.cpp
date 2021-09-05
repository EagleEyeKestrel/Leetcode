//
//  main.cpp
//  dp[mask]表示mask状态的数 能凑到的余数（余数肯定是唯一的）
//  考虑加入新数nums[i]，如果加起来大于target就跳过。我们让dp[mask]中的余数是无法拆分的，如果可以拆，那完全可以用其他几个数代替。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        for (int num: nums) s += num;
        if (s % k) return false;
        int target = s / k;
        int dp[1 << n];
        for (int i = 0; i < 1 << n; i++) dp[i] = -1;
        dp[0] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                if (dp[mask] + nums[i] > target) continue;
                dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
