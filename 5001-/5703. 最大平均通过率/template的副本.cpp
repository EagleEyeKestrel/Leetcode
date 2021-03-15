//
//  main.cpp
//  不一定是往通过率最小的去添加学生，比如1/2和4/8 ，添加一个学生显然效果不一样
//  直接按一次增加学生能增加多少通过率 建立堆
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            double a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
            double v1 = (a1 + 1) / (a2 + 1) - a1 / a2;
            double v2 = (b1 + 1) / (b2 + 1) - b1 / b2;
            return v1 < v2;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto &v: classes) {
            pq.push({ v[0], v[1] });
        }
        for (int i = 0; i < extraStudents; i++) {
            auto tmp = pq.top();
            pq.pop();
            pq.push({ tmp.first + 1, tmp.second + 1 });
        }
        double res = 0;
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            res += (double)tmp.first / tmp.second;
        }
        return res / classes.size();
    }
};
