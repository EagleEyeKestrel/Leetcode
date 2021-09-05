//
//  main.cpp
//  重新想了下，这个方法好。用dp[i][j]维护以nums[i] nums[j]两项结尾的最长序列
//  mp维护一个值 对应在nums中最后一次出现的值
//  关键是只需要记录最后一次出现的值就可以了。因为dp[mp[target]][i] 显然只可能比之前出现的解更优
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 2;
        unordered_map<int, int> mp;
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = 2 * nums[i] - nums[j];
                if (!mp.count(target)) {
                    dp[i][j] = 2;
                    continue;
                }
                dp[i][j] = dp[mp[target]][i] + 1;
                res = max(res, dp[i][j]);
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
