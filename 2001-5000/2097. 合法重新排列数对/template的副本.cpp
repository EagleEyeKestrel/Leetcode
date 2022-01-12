//
//  main.cpp
//  第一次在leetcode上做到关于欧拉图的题
//  首先，开始我想的是把每个pair作为顶点然后连边，但那个就变成了哈密顿通路问题，不好解
//  之前一直没想过为什么euler里是先递归，再存到res，再reverse
//  其实就是避免先走入死路的情况。可以发现在这种情况里，走入死路是最先输出的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> in, out;
    void euler(int u) {
        while (!g[u].empty()) {
            int v = g[u].back();
            g[u].pop_back();
            euler(v);
            res.push_back({u, v});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto &edge: pairs) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            in[v]++, out[u]++;
        }
        int start = -1;
        for (auto [i, val]: out) {
            if (in[i] == out[i] - 1) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            for (auto [i, val]: in) {
                if (out[i] > 0) {
                    start = i;
                    break;
                }
            }
        }
        euler(start);
        reverse(res.begin(), res.end());
        return res;
    }
};
