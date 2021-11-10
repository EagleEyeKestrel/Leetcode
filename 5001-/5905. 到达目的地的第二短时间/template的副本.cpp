//
//  main.cpp
//  第一次前三题做这么快，没想到卡在了这里
//  首先要明白，只要确定走过的边的个数，就能确定到达时间，计算过程在f里，注意要单独讨论最后一段
//  另一方面，第二小的距离，肯定不会超过dis+2。那么我们只需检查是否存在dis+1
//  开始我的做法是遍历节点i，看是否存在连着的点距离也为d[i]，但这其实是不对的。因为从i到n不一定是最短路
//  所以，一种做法是，从n开始bfs，检查沿路的某个节点i，是否存在相邻点j，使得d[j]==d[i]即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int dis, int t, int change) {
        int res = 0;
        for (int i = 0; i < dis - 1; i++) {
            res += t;
            if (res % (2 * change) >= change) res += 2 * change - res % (2 * change);
        }
        return res + t;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int t, int change) {
        vector<int> g[n + 1];
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        int vis[n + 1], d[n + 1];
        memset(vis, 0, sizeof(vis));
        vis[1] = 1, d[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int to: g[tmp]) {
                if (!vis[to]) {
                    vis[to] = 1;
                    q.push(to);
                    d[to] = d[tmp] + 1;
                }
            }
        }
        int flag = 0;
        int now = n;
        while (!q.empty()) q.pop();
        q.push(now);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            int ok = 0;
            for (int to: g[tmp]) {
                if (d[to] == d[tmp]) {
                    ok = 1;
                }
                if (d[to] == d[tmp] - 1) {
                    q.push(to);
                }
            }
            if (ok) {
                flag = 1;
                break;
            }
        }
        if (flag) return f(d[n] + 1, t, change);
        return f(d[n] + 2, t, change);
    }
};
