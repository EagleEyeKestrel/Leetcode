//
//  main.cpp
//  不难。和题目 最佳观光组合 类似
//  首先化简式子变成xj + yj + (yi - xi)
//  遍历xj + yj，然后最佳观光组合对i的范围没有限制，只需要i<j即可，这里i的范围有了限制
//  用单调队列维护i的范围，也是维护一个滑动窗口最大值的问题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(), res = INT_MIN;
        deque<int> q;
        for (int r = 1; r < n; r++) {
            while (!q.empty() && points[q.front()][0] < points[r][0] - k) q.pop_front();
            while (!q.empty() && points[r - 1][1] - points[r - 1][0] >= points[q.back()][1] - points[q.back()][0]) q.pop_back();
            if (points[r - 1][0] >= points[r][0] - k) {
                q.push_back(r - 1);
            }
            if (!q.empty()) res = max(res, points[r][1] + points[r][0] + points[q.front()][1] - points[q.front()][0]);
        }
        return res;
    }
};
