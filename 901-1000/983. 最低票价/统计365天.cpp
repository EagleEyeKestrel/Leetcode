//
//  main.cpp
//  O(n)的做法。。考虑到days长度很小，于是直接对365天统计一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[400], vis[400];
        memset(vis, 0, sizeof(vis));
        for(int day: days) vis[day] = 1;
        dp[0] = 0;
        for(int i = 1; i <= 365; i++) {
            if(!vis[i]) dp[i] = dp[i - 1];
            else {
                int v1 = dp[i - 1] + costs[0];
                int v2 = i >= 7 ? dp[i - 7] + costs[1] : costs[1];
                int v3 = i >= 30 ? dp[i - 30] + costs[2] : costs[2];
                dp[i] = min(min(v1, v2), v3);
            }
        }
        return dp[365];
    }
};
