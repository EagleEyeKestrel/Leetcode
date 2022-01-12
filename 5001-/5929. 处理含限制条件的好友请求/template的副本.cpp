//
//  main.cpp
//  并查集。一看时间复杂度的要求不高，所以可以遍历restrictions检查
//  每次要合并pi和pj，对于每个限制u,v，uv之前一定不在同一个联通块里，这次如果合并是非法的，无非就两种情况。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[1024];
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        p[px] = py;
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        for (int i = 0; i < n; i++) p[i] = i;
        vector<bool> res;
        for (auto &q: requests) {
            int i = q[0], j = q[1];
            int pi = find(i), pj = find(j);
            int flag = 1;
            for (auto &r: restrictions) {
                int u = find(r[0]), v = find(r[1]);
                if (pi == u && pj == v || pi == v && pj == u) {
                    flag = 0;
                    break;
                }
            }
            if (flag) merge(i, j);
            res.push_back((bool)flag);
        }
        return res;
    }
};
