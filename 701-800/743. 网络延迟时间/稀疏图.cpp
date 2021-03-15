//
//  main.cpp
//  稀疏图的做法，堆优化，复杂度O(ElogE)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n + 1], vis[n + 1];
        vector<pair<int, int>> graph[n + 1];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            dis[i] = 1e9;
        }
        for (auto &t: times) {
            graph[t[0]].push_back({ t[2], t[1] });
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[k] = 0;
        pq.push({ 0, k });
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if (tmp.first > dis[tmp.second]) continue;
            for (auto &edge: graph[tmp.second]) {
                if (dis[edge.second] > tmp.first + edge.first) {
                    dis[edge.second] = tmp.first + edge.first;
                    pq.push({ dis[edge.second], edge.second});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, dis[i]);
        return res == 1e9 ? -1 : res;
    }
};
