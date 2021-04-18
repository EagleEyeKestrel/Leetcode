//
//  main.cpp
//  逻辑实现题，第一次知道堆里如果用的是greater，那必须要重载大于号而非小于号。
//  用now表示当前时间，把在时间范围内的任务都压进堆
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct task {
        int eq, pro, index;
        bool operator > (const task& t) const {
            if (pro == t.pro) return index > t.index;
            return pro > t.pro;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), id = 0;
        for (int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        long long now = tasks[0][0];
        priority_queue<task, vector<task>, greater<task>> pq;
        vector<int> res;
        while (id < n) {
            while (id < n && tasks[id][0] <= now) {
                task newtask;
                newtask.eq = tasks[id][0];
                newtask.pro = tasks[id][1];
                newtask.index = tasks[id][2];
                pq.push(newtask);
                id++;
            }
            if (pq.empty()) {
                now = tasks[id][0];
            } else {
                auto tmp = pq.top();
                pq.pop();
                res.push_back(tmp.index);
                now += tmp.pro;
            }
        }
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            res.push_back(tmp.index);
        }
        return res;
    }
};
