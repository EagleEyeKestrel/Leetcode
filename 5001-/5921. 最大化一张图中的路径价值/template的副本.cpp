//
//  main.cpp
//  服了，很无聊的题，关键在于看t，不会超过走10步，直接dfs
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int res = 0;
    vector<pair<int, int>> g[1010];
    void dfs(int u, int t, int val, unordered_set<int> &vis, vector<int> &values, int maxTime) {
        if (t > maxTime) return;
        if (u == 0) {
            res = max(res, val);
        }
        for (auto &pi: g[u]) {
            if (t + pi.second <= maxTime) {
                int flag = vis.count(pi.first);
                if (!flag) vis.insert(pi.first);
                dfs(pi.first, t + pi.second, flag ? val : val + values[pi.first], vis, values, maxTime);
                if (!flag) vis.erase(pi.first);
            }
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        for (auto &e: edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        unordered_set<int> vis = {0};
        dfs(0, 0, values[0], vis, values, maxTime);
        return res;
    }
};
