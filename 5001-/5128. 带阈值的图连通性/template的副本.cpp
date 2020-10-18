//
//  main.cpp
//  211场周赛真的是第二题最难。。
//  并查集预处理一下就好了，对所有因数，有这个公因数的就连边，这个的过程大概是nlgn的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int fa[10010];
    int findp(int x) {
        if(fa[x] != x) {
            fa[x] = findp(fa[x]);
        }
        return fa[x];
    }
    void merge(int i, int j) {
        int pa = findp(i), pb = findp(j);
        fa[pb] = pa;
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = threshold + 1; i < n; i++) {
            for(int j = i + i; j <= n; j += i) {
                merge(i, j);
            }
        }
        vector<bool> res;
        for(auto &q: queries) {
            res.push_back(findp(q[0]) == findp(q[1]));
        }
        return res;
    }
};
