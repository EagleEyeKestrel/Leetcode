//
//  main.cpp
//  并查集裸题，按秩合并
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[256], sz[256];
    int findp(int x) {
        return x == p[x] ? x : (p[x] = findp(p[x]));
    }
    void merge(int i, int j) {
        int pi = findp(i), pj = findp(j);
        if (sz[pi] <= sz[pj]) {
            p[pi] = pj;
        } else {
            p[pj] = pi;
        }
        if (sz[pi] == sz[pj] && pi != pj) sz[pj]++;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && i != j) {
                    merge(i + 1, j + 1);
                }
            }
        }
        unordered_set<int> res;
        for (int i = 1; i <= n; i++) res.insert(findp(i));
        return res.size();
    }
};
