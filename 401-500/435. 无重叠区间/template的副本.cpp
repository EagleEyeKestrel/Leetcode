//
//  main.cpp
//  比较简单，等价于活动安排问题，求最多能同时容下多少个活动？
//  按右端点排序，贪心选择，得到最多能容下res个区间。那么就应该删除n-res个
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int res = 1;
        auto tmp = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= tmp[1]) {
                tmp = intervals[i];
                res++;
            }
        }
        return n - res;
    }
};
