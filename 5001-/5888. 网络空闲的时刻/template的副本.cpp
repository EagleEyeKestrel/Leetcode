//
//  main.cpp
//  题目很吓人，其实就是处理出每个点到0的最小距离，然后就是简单计算一下了
//  算距离的话，这里用堆优化的dij，当然bfs就可以了，因为权值都是1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        int dis[n];
        vector<pair<int, int>> g[n];
        for (int i = 0; i < n; i++) dis[i] = 1e9;
        for (auto &edge: edges) {
            g[edge[0]].push_back({1, edge[1]});
            g[edge[1]].push_back({1, edge[0]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if (tmp.first > dis[tmp.second]) continue;
            for (auto &edge: g[tmp.second]) {
                if (dis[edge.second] > tmp.first + edge.first) {
                    dis[edge.second] = tmp.first + edge.first;
                    pq.push({dis[edge.second], edge.second});
                }
            }
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            int t = dis[i] * 2;
            int lastt = t % patience[i] ? t / patience[i] * patience[i] : (t / patience[i] - 1) * patience[i];
            res = max(res, lastt + t);
        }
        return res + 1;
    }
};
