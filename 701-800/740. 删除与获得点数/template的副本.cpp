//
//  main.cpp
//  本质上和打家劫舍差不多，获得一个数的点数，就不能获得相邻的点数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int cnt[10010], dp[10010];
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        for(int num: nums) cnt[num]++;
        for(int i = 1; i <= 10000; i++) {
            dp[i] = max(dp[i - 1], cnt[i] * i + (i >= 2 ? dp[i - 2] : 0));
        }
        return dp[10000];
    }
};
