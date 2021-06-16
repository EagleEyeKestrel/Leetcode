//
//  main.cpp
//  用dp[i]表示一个位置i能否到达，递推公式如注释所示
//  存一下dp的前缀和，就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int dp[n], sum[n];
        dp[0] = 1;
        sum[0] = 1;
        //dp[i] = (dp[i - maxJump] + ... + dp[i - minJump] != 0);
        for (int i = 1; i < n; i++) {
            int r = i - minJump, l = max(0, i - maxJump);
            if (r < 0 || s[i] == '1') {
                dp[i] = 0, sum[i] = sum[i - 1];
                continue;
            }
            int tmp = sum[r] - (l ? sum[l - 1] : 0);
            dp[i] = (tmp != 0);
            sum[i] = sum[i - 1] + dp[i];
        }
        return dp[n - 1];
    }
};
