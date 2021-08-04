//
//  main.cpp
//  关键在于递推方程 对于一对父子(p,u) ans[u] = ans[p] - (num[u] - 1) + n - 1 - num[u];
//  num[u]表示以u为根的子树的元素个数
//  即u这个子树内，所有点的距离会-1 而之外部分全部+1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    int num[50010], vis[50010], d[50010];
    vector<int> g[50010];
    vector<int> ans;
    void dfs(int u, int h) {
        int res = 1;
        vis[u] = 1;
        d[u] = h;
        for (int v: g[u]) {
            if (!vis[v]) {
                dfs(v, h + 1);
                res += num[v];
            }
        }
        num[u] = res;
    }
    void dfs2(int u, int p) {
        vis[u] = 1;
        if (p != -1) {
            ans[u] = ans[p] - (num[u] - 1) + n - 1 - num[u];
        }
        for (int v: g[u]) {
            if (!vis[v]) {
                dfs2(v, u);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        ans = vector<int>(n, 0);
        for (int j = 1; j < n; j++) ans[0] += d[j];
        memset(vis, 0, sizeof(vis));
        dfs2(0, -1);
        return ans;
    }
};
