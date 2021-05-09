//
//  main.cpp
//  找有没有环很容易，拓扑排序即可
//  用dp[v][c]表示以v为终点时，路径上颜色为c的最大数目。
//  转移方程 dp[v][c] = max{ dp[u][c] + (color[v] == c) }
//  状态转移可以在拓扑的同时进行，因为边的关系在拓扑时都会用到
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size(), cnt = 0, res = 0;
        int indegree[n];
        vector<int> g[n];
        memset(indegree, 0, sizeof(indegree));
        for (auto &edge: edges) {
            indegree[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
        }
        int dp[n][26];
        memset(dp, 0, sizeof(dp));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        while (!q.empty()) {
            cnt++;
            int u = q.front();
            q.pop();
            for (int v: g[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
                for (int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c], dp[u][c] + (colors[v] - 'a' == c));
                }
            }
        }
        if (cnt != n) return -1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) res = max(res, dp[i][c]);
        }
        return res;
    }
};
