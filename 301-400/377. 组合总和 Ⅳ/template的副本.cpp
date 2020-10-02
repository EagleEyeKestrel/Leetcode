//
//  main.cpp
//  dp[i]表示当前组合总和为i的种数
//  这里的不同顺序也视为不同组合。。如果不考虑顺序，那么就用背包
//  然后有个比较坑的用例，需要用unsigned ll才能过
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unsigned long long dp[target + 1];
        dp[0] = 1;
        for(int j = 1; j <= target; j++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                if(j >= nums[i]) {
                    tmp += dp[j - nums[i]];
                }
            }
            dp[j] = tmp;
        }
        return dp[target];
    }
};
