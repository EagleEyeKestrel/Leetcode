//
//  main.cpp
//  并查集题，每次两个点联通，找到第一条连接两个已经联通的点的边
//  之后不可能再有了，因为要成树必须要有n-1条边
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[1024], sz[1024];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int x, int y) {
        int px = findp(x), py = findp(y);
        if (sz[px] <= sz[py]) {
            p[px] = py;
        } else {
            p[py] = px;
        }
        if (sz[px] == sz[py] && px != py) {
            sz[py]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
        for (auto &edge: edges) {
            if (findp(edge[0]) == findp(edge[1])) return edge;
            merge(edge[0], edge[1]);
        }
        return {};
    }
};
