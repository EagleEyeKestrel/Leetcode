//
//  main.cpp
//  图论+排列组合问题
//  根据prevRoom其实就可以轻易画出这个图，这个图也是唯一的，我们可以存下来，记作g
//  关键就是怎么求种类数
//  可以发现对于一个子树u，假设子树包含了num个节点，那么u在这num个节点中必须位于第一个
//  所以由于u的限制，所有的排列数要除以num
//  所以只需要求出(n-1)!，然后统计每一个节点的子树节点个数num，依次除以num即可
//  统计num只需要dfs一遍即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    long long qpow(long long x, int num) {
        long long res = 1;
        while (num) {
            if (num & 1) res = (res * x) % mod;
            num >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }
    vector<int> g[100010];
    int d[100010];
    int dfs(int u) {
        if (g[u].empty()) {
            d[u] = 1;
            return 1;
        }
        d[u] = 1;
        for (int v: g[u]) {
            d[u] += dfs(v);
        }
        return d[u];
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        long long res = 1;
        int n = prevRoom.size(), cnt = 0;
        for (int i = 1; i <= n - 1; i++) {
            res = (res * i) % mod;
        }
        for (int i = 1; i < n; i++) {
            g[prevRoom[i]].push_back(i);
        }
        dfs(0);
        for (int i = 1; i < n; i++) {
            long long div = qpow(d[i], mod - 2);
            res = (res * div) % mod;
        }
        return res;
        
    }
};
