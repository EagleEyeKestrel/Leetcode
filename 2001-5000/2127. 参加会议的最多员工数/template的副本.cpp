//
//  main.cpp
//  可以看解析，讲的很明确。分成两种情况，图中肯定带环。一种是环大小>=3，一种是=2
//  大于等于3的环，最大那就是 环的长度
//  长度等于2的环，最大就是 两个端点 最长链 长度之和
//  怎么求最长链？这里用l数组递推。递推的时候注意要处理u 和 v互相连通的情况，所以是在遍历到u的时候去更新v更好
//  因为v可能不被bfs遍历到
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumInvitations(vector<int>& f) {
        int n = f.size();
        int vis[n], in[n], l[n];
        memset(vis, 0, sizeof(vis));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n; i++) {
            in[f[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
            l[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int to = f[u];
            in[to]--;
            l[to] = max(l[to], l[u] + 1);
            if (in[to] == 0) {
                q.push(to);
            }
        }
        int sumChain = 0, maxround = 0;
        for (int start = 0; start < n; start++) {
            if (vis[start]) continue;
            int now = start;
            vector<int> seq;
            while (!vis[now]) {
                seq.push_back(now);
                vis[now] = 1;
                now = f[now];
            }
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] == now) {
                    int C = seq.size() - i;
                    if (C == 2) {
                        sumChain += l[seq.back()] + l[seq[seq.size() - 2]];
                    }
                    else maxround = max(maxround, C);
                }
            }
        }
        return max(maxround, sumChain);
    }
};