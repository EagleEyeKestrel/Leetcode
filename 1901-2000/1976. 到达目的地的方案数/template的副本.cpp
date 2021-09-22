//
//  main.cpp
//  先处理出所有的单源最短路径
//  之前做了一个所有边长度都为1的问方案数可以直接bfs，这个不行，因为每条边长度不一
//  这里先按距离排序了，然后在按距离从小到大进行dp累加
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long dis[n], g[n][n], vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            dis[i] = 1e17;
            for (int j = 0; j < n; j++) g[i][j] = 1e17;
        }
        for (auto &edge: roads) {
            g[edge[0]][edge[1]] = edge[2];
            g[edge[1]][edge[0]] = edge[2];
        }
        dis[0] = 0;
        for (int i = 0; i < n; i++) {
            long long minv = 1e17, minid = -1;
            for (int u = 0; u < n; u++) {
                if (!vis[u] && dis[u] < minv) {
                    minv = dis[u];
                    minid = u;
                }
            }
            vis[minid] = 1;
            for (int j = 0; j < n; j++) {
                dis[j] = min(dis[j], dis[minid] + g[minid][j]);
            }
        }
        int mod = 1e9 + 7;
        int res[n];
        memset(res, 0, sizeof(res));
        res[0] = 1;
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = i;
        sort(v.begin(), v.end(), [&](int a, int b) {
            return dis[a] < dis[b];
        });
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (g[v[i]][v[j]] != 1e17 && dis[v[i]] == dis[v[j]] + g[v[i]][v[j]]) {
                    res[v[i]] = (res[v[i]] + res[v[j]]) % mod;
                }
            }
        }
        return res[n - 1];
    }
};
