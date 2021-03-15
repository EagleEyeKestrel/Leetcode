//
//  main.cpp
//  挺难的一道图论题（我的意思是在中等题里面算coding比较复杂的
//  思路很简单，用Dijkstra处理出每个点到n的距离，然后跑一遍dp
//  其中u点的种类数等于sum dp[v]，其中v是u的连边且v到n的距离比u到n的距离更小
//  注意Dijkstra要用堆优化，否则O(n2)会超时
//  WA了一次，一开始将dis初始化为1e9，是有问题的，因为本题的数据范围，有的点到n的距离会超过1e9
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int dis[n + 1];
        vector<pair<int, int>> graph[n + 1];
        for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
        for (auto &t: edges) {
            graph[t[0]].push_back({ t[2], t[1] });
            graph[t[1]].push_back({ t[2], t[0] });
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[n] = 0;
        pq.push({ 0, n });
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            if (tmp.first > dis[tmp.second]) continue;
            for (auto &edge: graph[tmp.second]) {
                if (dis[edge.second] > tmp.first + edge.first) {
                    dis[edge.second] = tmp.first + edge.first;
                    pq.push({ dis[edge.second], edge.second});
                }
            }
        }
        vector<int> points;
        for (int i = 1; i <= n; i++) points.push_back(i);
        sort(points.begin(), points.end(), [&](int a, int b) {
            return dis[a] < dis[b];
        });
        int dp[n + 1];
        dp[n] = 1;
        for (int i = 2; i <= n; i++) {
            int u = points[i - 1], cnt = 0;
            for (auto &edge: graph[u]) {
                if (dis[edge.second] < dis[u]) {
                    cnt = (cnt + dp[edge.second]) % mod;
                }
            }
            dp[u] = cnt;
        }
        return dp[1];
    }
};
