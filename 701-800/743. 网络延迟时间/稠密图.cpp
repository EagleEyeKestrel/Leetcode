//
//  main.cpp
//  稠密图Dijkstra模版，复杂度O(n2)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n + 1], graph[n + 1][n + 1], vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            dis[i] = 1e9;
            for (int j = 1; j <= n; j++) graph[i][j] = 1e9;
        }
        for (auto &t: times) {
            graph[t[0]][t[1]] = t[2];
        }
        dis[k] = 0;
        for (int i = 1; i <= n; i++) {
            int minv = INT_MAX, minid = -1;
            for (int u = 1; u <= n; u++) {
                if (!vis[u] && dis[u] < minv) {
                    minid = u;
                    minv = dis[u];
                }
            }
            vis[minid] = 1;
            for (int j = 1; j <= n; j++) {
                dis[j] = min(dis[j], dis[minid] + graph[minid][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, dis[i]);
        return res == 1e9 ? -1 : res;
    }
};
