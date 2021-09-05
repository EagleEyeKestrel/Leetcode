//
//  main.cpp
//  做法之一，用mp[i]维护一个地方 {公差，最长等差序列长度}，然后O(n2)穷举后两项dp
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 2;
        unordered_map<int, int> mp[n];
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        mp[1].insert({nums[1] - nums[0], 2});
        for (int i = 2; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                int d = nums[i] - nums[j];
                if (mp[j].count(d)) {
                    dp[i] = max(dp[i], mp[j][d] + 1);
                    if (!mp[i].count(d)) mp[i][d] = mp[j][d] + 1;
                    else mp[i][d] = max(mp[i][d], mp[j][d] + 1);
                } else {
                    dp[i] = max(dp[i], 2);
                    mp[i][d] = 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
