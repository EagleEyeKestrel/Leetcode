//
//  main.cpp
//  按结束时间排序，然后二分找到不冲突的索引
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto &v1, auto &v2) {
            return v1[1] < v2[1];
        });
        int end[n], maxv[n];
        for (int i = 0; i < n; i++) end[i] = events[i][1];
        maxv[0] = events[0][2];
        for (int i = 1; i < n; i++) maxv[i] = max(maxv[i - 1], events[i][2]);
        int res = events[0][2];
        for (int i = 1; i < n; i++) {
            int id = lower_bound(end, end + n, events[i][0]) - end - 1;
            if (id < 0) {
                res = max(res, events[i][2]);
                continue;
            }
            res = max(res, events[i][2] + maxv[id]);
        }
        return res;
    }
};
