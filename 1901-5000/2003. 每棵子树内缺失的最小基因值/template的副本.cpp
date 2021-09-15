//
//  main.cpp
//  第一次学习到树上的启发式算法，第一次见，按小往大并，如果出现大往小的并的情况，直接交换即可
//  启发式算法的合并是O(nlogn)的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> g[100010];
    unordered_set<int> s[100010];
    vector<int> mex;
    void dfs(int u, int p, vector<int> &nums) {
        mex[u] = 1;
        for (int v: g[u]) {
            if (v != p) {
                dfs(v, u, nums);
                if (s[v].size() > s[u].size()) swap(s[u], s[v]);
                for (int x: s[v]) {
                    s[u].insert(x);
                }
                mex[u] = max(mex[u], mex[v]);
            }
        }
        s[u].insert(nums[u]);
        while (s[u].count(mex[u])) mex[u]++;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        for (int i = 1; i < n; i++) {
            int v = parents[i];
            g[i].push_back(v);
            g[v].push_back(i);
        }
        mex = vector<int>(n, 1);
        dfs(0, -1, nums);
        return mex;
    }
};
