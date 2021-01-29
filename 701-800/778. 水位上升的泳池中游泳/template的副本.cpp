//
//  main.cpp
//  不是很难的一道Hard
//  这里是并查集的写法，因为已经明确地图的高度是一个排列，所以可以存每个高度的位置
//  还可以二分高度，dfs/bfs check是否可行
//  也可以用Dijkstra，因为没有负权边
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[10000];
    int direx[4] = { -1, 0, 0, 1 };
    int direy[4] = { 0, -1, 1, 0 };
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int a, int b) {
        int pa = findp(a), pb = findp(b);
        p[pa] = pb;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n * n; i++) p[i] = i;
        int pos[2550];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = i * n + j;
            }
        }
        for (int t = 0; t < n * n; t++) {
            int x = pos[t] / n, y = pos[t] % n;
            for (int k = 0; k < 4; k++) {
                int newx = x + direx[k], newy = y + direy[k];
                if (newx < 0 || newx >= n || newy < 0 || newy >= n) continue;
                if (grid[newx][newy] < t) {
                    merge(pos[t], newx * n + newy);
                }
            }
            if (findp(0) == findp(n * n - 1)) return t;
        }
        return -1;
    }
};
