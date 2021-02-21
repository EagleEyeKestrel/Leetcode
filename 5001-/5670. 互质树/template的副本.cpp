//
//  main.cpp
//  遍历祖先估计会超时
//  发现nums的数字范围很小，考虑从此入手
//  维护一个数组v，v[i]记录的是，遍历到某个节点时，值为i的最近的祖先的编号
//  然后就bfs解决，每次检查50个值，depth记录某个编号节点的深度
//  tmpv这里用的是引用，大概1000ms左右。如果不用的话慢一些，1600ms，但也能过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> g[100010];
    int vis[100010], depth[100010];
    int gcd(int a, int b) {
        return a % b ? gcd(b, a % b) : b;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        memset(vis, 0, sizeof(vis));
        vector<int> v(51, -1);
        vector<int> res(n, -1);
        queue<pair<int, vector<int>>> q;
        pair<int, vector<int>> root = make_pair(0, v);
        depth[0] = 0;
        vis[0] = 1;
        q.push(root);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int id = tmp.first;
            vector<int> &tmpv = tmp.second;
            for (int i = 1; i <= 50; i++) {
                if (tmpv[i] != -1 && gcd(i, nums[id]) == 1) {
                    if (res[id] == -1) {
                        res[id] = tmpv[i];
                    } else {
                        if (depth[tmpv[i]] > depth[res[id]]) res[id] = tmpv[i];
                    }
                }
            }
            for (int to: g[id]) {
                if (vis[to]) continue;
                depth[to] = depth[id] + 1;
                vis[to] = 1;
                tmpv[nums[id]] = id;
                q.push(make_pair(to, tmpv));
            }
        }
        return res;
    }
};
