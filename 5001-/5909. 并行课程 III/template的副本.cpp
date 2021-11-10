//
//  main.cpp
//  比较简单的最后一题，其实只有中等题难度
//  拓扑排序，然后找到其中最长的一条路径
//  reach[i]表示在i之前，最后一个课程完成的时间
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> g[50010];
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& t) {
        int in[n + 1], reach[n + 1];
        memset(in, 0, sizeof(in));
        for (auto &e: relations) {
            in[e[1]]++;
            g[e[0]].push_back(e[1]);
        }
        for (int i = 1; i <= n; i++) reach[i] = 0;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                reach[i] = 0;
            }
        }
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int to: g[tmp]) {
                in[to]--;
                reach[to] = max(reach[to], reach[tmp] + t[tmp - 1]);
                if (in[to] == 0) {
                    q.push(to);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, reach[i] + t[i - 1]);
        return res;
    }
};
