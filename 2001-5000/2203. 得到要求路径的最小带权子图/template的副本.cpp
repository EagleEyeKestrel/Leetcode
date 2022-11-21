//
//  main.cpp
//  不错的题
//  关键是要知道最终的图长什么样子？一定是两条路径。那么就穷举两条路径的交汇点
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<long long> dis1, dis2, dis3;
    void dij(vector<vector<int>> &edges, int n, int k, vector<long long> &dis) {
        vector<pair<int, int>> graph[n + 1];
        for (int i = 0; i < n; i++) dis[i] = 1e18;
        for (auto &e: edges) graph[e[0]].push_back({e[2], e[1]});
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dis[k] = 0;
        pq.push({ 0, k });
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if (tmp.first > dis[tmp.second]) continue;
            for (auto &edge: graph[tmp.second]) {
                if (dis[edge.second] > tmp.first + edge.first) {
                    dis[edge.second] = tmp.first + edge.first;
                    pq.push({dis[edge.second], edge.second});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        dis1 = vector<long long>(n);
        dis2 = vector<long long>(n);
        dis3 = vector<long long>(n);
        dij(edges, n, src1, dis1);
        dij(edges, n, src2, dis2);
        for (auto &e: edges) swap(e[0], e[1]);
        dij(edges, n, dest, dis3);
        if (dis1[dest] == 1e18 || dis2[dest] == 1e18) return -1;
        long long res = 1e18;
        for (int i = 0; i < n; i++) {
            res = min(res, dis1[i] + dis2[i] + dis3[i]);
        }
        return res;
    }
};