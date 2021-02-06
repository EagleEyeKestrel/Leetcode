//
//  main.cpp
//  直接贴比赛时的代码
//  容易看出n个event的情况下，dp[i][j]表示前i(i从0开始)活动，参加恰好j个活动的最大价值
//  为了找出递推关系，给活动按结束时间排序，这样可以方便找出和最后一个活动不冲突的活动们
//  可以发现dp[i][j]的递推方程，如果不取i，那么就是dp[i-1][j]
//  关键是取i时，要找到和i活动不冲突的活动们。可以知道i活动的starttime
//  然后要找到结束时间<starttime的所有活动，直接二分查找id，在前id-1安排恰好j-1个活动
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[1] < b[1];
        });
        int a[n];
        for (int i = 0; i < n; i++) a[i] = events[i][1];
        int dp[n][k + 1];
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        dp[0][1] = events[0][2];
        for (int j = 2; j <= k; j++) dp[0][j] = INT_MIN;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k && j <= i + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                int starttime = events[i][0];
                int id = lower_bound(a, a + n, starttime) - a;
                if (id == 0) {
                    dp[i][j] = max(dp[i][j], events[i][2]);
                } else {
                    dp[i][j] = max(dp[i][j], dp[id - 1][j - 1] + events[i][2]);
                }
            }
            for (int j = i + 2; j <= k; j++) dp[i][j] = INT_MIN;
        }
        int res = INT_MIN;
        for (int j = 0; j <= k; j++) res = max(res, dp[n - 1][j]);
        return res;
    }
};
