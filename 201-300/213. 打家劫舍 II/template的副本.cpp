//
//  main.cpp
//  问题等价于，比最简单的打家劫舍多了一个条件，最后一个和第一个不能同时取
//  那最简单的想法就是，分两种情况，一种对0到n-2进行dp，另一种对1到n-1进行dp
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(!n) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        res = max(res, dp[n - 2]);
        memset(dp, 0, sizeof(dp));
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for(int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return max(res, dp[n - 1]);
    }
};
