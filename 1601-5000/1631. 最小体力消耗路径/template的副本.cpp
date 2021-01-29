//
//  main.cpp
//  直接的dp有点难想，这里直接用bfs了
//  h[i][j]记录到(i,j)的最小开销。每次如果发现h[i][j]可以更新，就push新状态进入队列
//  另外，Dijkstra也可以。但是估计需要优先队列优化
//  另外一种思路，用并查集。把边权值从小到大开始处理联通，直到左上和右下发现联通
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {-1, 0, 0, 1};
    int direy[4] = {0, -1, 1, 0};
    int m, n;
    bool inmap(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    struct node {
        int i, j, h;
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        int h[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                h[i][j] = 1e9;
            }
        }
        h[0][0] = 0;
        queue<node> q;
        node tmp;
        tmp.i = 0;
        tmp.j = 0;
        tmp.h = 0;
        q.push(tmp);
        while(!q.empty()) {
            tmp = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int newi = tmp.i + direx[k], newj = tmp.j + direy[k];
                if(inmap(newi, newj)) {
                    int dh = abs(heights[newi][newj] - heights[tmp.i][tmp.j]);
                    if(h[newi][newj] > max(dh, h[tmp.i][tmp.j])) {
                        h[newi][newj] = max(dh, h[tmp.i][tmp.j]);
                        node newtmp;
                        newtmp.i = newi;
                        newtmp.j = newj;
                        newtmp.h = h[newi][newj];
                        q.push(newtmp);
                    }
                }
            }
        }
        return h[m - 1][n - 1];
    }
};
