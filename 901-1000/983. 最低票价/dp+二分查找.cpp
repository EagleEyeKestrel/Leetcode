//
//  main.cpp
//  O(nlogn)的做法，dp[i]表示前i个旅游日期的最小花费，每次二分查找
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int i2 = lower_bound(days.begin(), days.end(), days[i - 1] - 6) - days.begin();
            int i3 = lower_bound(days.begin(), days.end(), days[i - 1] - 29) - days.begin();
            dp[i] = min(dp[i - 1] + costs[0], min(dp[i2] + costs[1], dp[i3] + costs[2]));
        }
        return dp[n];
    }
};
