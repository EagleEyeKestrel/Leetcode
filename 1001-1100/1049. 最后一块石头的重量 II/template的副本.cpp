//
//  main.cpp
//  其实就是看这么多石头，不超过一半的和最多是多少，尽量让这个和贴近一半，这个和就能被消掉
//  经典的dp,dp[i][j]表示前i个和不超过j的最大质量和，空间优化一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for(int stone: stones) sum += stone;
        int dp[sum / 2 + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            for(int j = sum / 2; j >= stones[i - 1]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * dp[sum / 2];
    }
};
