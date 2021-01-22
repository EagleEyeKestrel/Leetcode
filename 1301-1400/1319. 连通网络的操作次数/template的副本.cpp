//
//  main.cpp
//  本来以为会是MST问题，结果又是并查集的裸题
//  找到联通分支的个数k，那么就需要k-1根线把它们连起来。
//  MST需要n-1个线，那么一定有多余的线
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int a, int b) {
        int pa = findp(a), pb = findp(b);
        p[pa] = pb;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int l = connections.size();
        if (l < n - 1) return -1;
        for (int i = 0; i < n; i++) p[i] = i;
        for (auto& connection: connections) {
            merge(connection[0], connection[1]);
        }
        unordered_set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(findp(i));
        return roots.size() - 1;
    }
};
