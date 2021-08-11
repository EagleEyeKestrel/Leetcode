//
//  main.cpp
//  用s1表示+ 的和，s2表示-的部分 那么可以得到s1=(s+target)/2
//  注意判断一下能否被2整除，否则可能因为int的精度问题给出错误答案
//  然后就是简单的背包问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    //s1-s2=target, s1+s2=s
    //s1=(s+target)/2
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), s = 0;
        for (int num: nums) s += num;
        if ((s + target) & 1) return 0;
        //dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]]
        int dp[1024];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = (s + target) / 2; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[(s + target) / 2];
    }
};
