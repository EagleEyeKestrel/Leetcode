//
//  main.cpp
//  带了点优化的bfs，但是优化要注意一些坑：
//  传送到的地方不会再次传送。所以有的点尽管vis不是0(来过)，但是上面的数字却并不一定去过
//  简单点的话，直接搜状态{id, step}，一样能过，甚至不需要判断是否走到过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    pair<int, int> id2rc(int x) {
        int r = (x - 1) / n;
        if (r % 2) return { n - 1 - r, n - 1 - (x - 1) % n };
        return { n - 1 - r, (x - 1) % n };
    }
    int vis[1000], d[1000];
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n * n; i++) d[i] = INT_MAX;
        queue<int> q;
        q.push(1);
        d[1] = 0;
        vis[1] = 1;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            if (tmp == n * n) break;
            for (int k = 1; k <= 6 && tmp + k <= n * n; k++) {
                int newtmp = tmp + k;
                auto pi = id2rc(newtmp);
                if (vis[newtmp] && board[pi.first][pi.second] == -1) continue;
                if (board[pi.first][pi.second] != -1) {
                    newtmp = board[pi.first][pi.second];
                }
                d[newtmp] = min(d[newtmp], d[tmp] + 1);
                if (!vis[newtmp]) q.push(newtmp);
                vis[newtmp] = 1;
            }
        }
        return d[n * n] == INT_MAX ? -1 : d[n * n];
    }
};
