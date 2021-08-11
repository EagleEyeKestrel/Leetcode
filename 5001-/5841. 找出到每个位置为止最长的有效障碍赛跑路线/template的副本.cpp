//
//  main.cpp
//  基本上就是nlogn求解LIS问题的裸题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size(), now = 0;
        vector<int> res(n);
        int dp[n];
        for (int i = 0; i < n; i++) {
            if (now == 0 || obstacles[i] >= dp[now - 1]) {
                dp[now++] = obstacles[i];
                res[i] = now;
            } else {
                auto it = upper_bound(dp, dp + now, obstacles[i]);
                *it = obstacles[i];
                res[i] = it - dp + 1;
            }
        }
        return res;
    }
};
