//
//  main.cpp
//  数据量很小，也没有什么特别好的方法，直接bfs
//  如果直接爆搜，肯定还是会超时的，我们要进行优化。可以想到 到一个点的时候
//  我们的状态包括，当前点now，已经覆盖到的点state，以及当前这是第几步step
//  可以发现，如果now和state完全一样 属于重复状态，这里包括4096*12种状态，正好不超时
//  所以用个vis记录已经到达过的状态，然后bfs就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int state, now, step;
        node (int _state, int _now, int _step) {
            state = _state, now = _now, step = _step;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_set<int> vis;
        queue<node> q;
        for (int i = 0; i < n; i++) {
            node st(1 << i, i, 0);
            q.push(st);
            vis.insert((1 << i) * 20 + i);
        }
        while (!q.empty()) {
            node tmp = q.front();
            q.pop();
            for (int to: graph[tmp.now]) {
                int newState = tmp.state | (1 << to);
                node nt(newState, to, tmp.step + 1);
                if (newState == (1 << n) - 1) return tmp.step + 1;
                if (!vis.count(newState * 20 + to)) {
                    q.push(nt);
                    vis.insert(newState * 20 + to);
                }
            }
        }
        return 0;
    }
};
