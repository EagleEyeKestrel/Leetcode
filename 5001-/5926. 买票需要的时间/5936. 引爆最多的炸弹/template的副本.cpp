//
//  main.cpp
//  开始没仔细读题，以为是并查集
//  然后才发现其实是图论题，就是说点燃i之后 根据条件 可能会点燃j，对i建立所有的j连边
//  然后只能选一个点，在他之后的所有可达的点都会被点燃
//  数据范围很小，穷举起点start，然后直接bfs即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long dis2(vector<vector<int>> &bombs, int i, int j) {
        long long x1 = bombs[i][0], y1 = bombs[i][1];
        long long x2 = bombs[j][0], y2 = bombs[j][1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    vector<int> g[110];
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long d = dis2(bombs, i, j);
                long long r = bombs[i][2];
                if (r * r >= d) {
                    g[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int start = 0; start < n; start++) {
            int vis[110];
            memset(vis, 0, sizeof(vis));
            queue<int> q;
            q.push(start);
            vis[start] = 1;
            int tmp = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int to: g[u]) {
                    if (!vis[to]) {
                        q.push(to);
                        vis[to] = 1;
                        tmp++;
                    }
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};
