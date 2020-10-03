//
//  main.cpp
//  dp[i][j]表示从i到j范围内先手能获得的最大分数
//  有个tricky的是当n为偶数一定获胜，可以优化一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int i = 0; i < n; i++) dp[i][i] = nums[i];
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
