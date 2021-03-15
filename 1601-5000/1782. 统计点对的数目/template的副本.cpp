//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/114607949
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> res(queries.size());
        unordered_map<int, int> mp;
        int d[20010], degrees[20010];
        memset(d, 0, sizeof(d));
        for (auto &edge: edges) {
            int u = min(edge[0], edge[1]);
            int v = max(edge[0], edge[1]);
            mp[u * 20001 + v]++;
            d[u]++, d[v]++;
        }
        for (int i = 1; i <= n; i++) degrees[i] = i;
        sort(degrees + 1, degrees + n + 1, [&](int a, int b) {
            return d[a] < d[b];
        });
        for (int i = 0; i < queries.size(); i++) {
            int cnt = queries[i];
            int r = n, sum1 = 0;
            unordered_set<int> dup;
            for (int l = 1; l < n; l++) {
                while (r > l && d[degrees[l]] + d[degrees[r]] > cnt) r--;
                sum1 += r > l ? n - r : n - l;
            }
            for (auto &edge: edges) {
                int u = min(edge[0], edge[1]);
                int v = max(edge[0], edge[1]);
                if (d[u] + d[v] > cnt && d[u] + d[v] - mp[20001 * u + v] <= cnt) dup.insert(20001 * u + v);
            }
            res[i] = sum1 - dup.size();
        }
        return res;
    }
};
