//
//  main.cpp
//  并查集
//  思路想到就不难了。把一个正方形按对角线分成四个部分，斜杠的本质是把某些区域隔开
//  比如正上方是1，然后逆时针转到1234四个区域
//  左斜杠表明12互通，34互通 右斜杠表示14互通，23互通
//  一共有4*m*n个区域，依次合并。别忘了合并一个正方形和相邻的正方形
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[4000], sz[4000];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int a, int b) {
        int pa = findp(a), pb = findp(b);
        if (sz[pa] <= sz[pb]) {
            p[pa] = pb;
        } else {
            p[pb] = pa;
        }
        if (sz[pa] == sz[pb] && pa != pb) {
            sz[pb]++;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i <= 4 * m * n; i++) p[i] = i, sz[i] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int id = ((i - 1) * n + j - 1) * 4;
                if (grid[i - 1][j - 1] == ' ') {
                    merge(id + 1, id + 2);
                    merge(id + 1, id + 3);
                    merge(id + 1, id + 4);
                }
                if (grid[i - 1][j - 1] == '/') {
                    merge(id + 1, id + 2);
                    merge(id + 4, id + 3);
                }
                if (grid[i - 1][j - 1] == '\\') {
                    merge(id + 1, id + 4);
                    merge(id + 2, id + 3);
                }
                if (i > 1) merge(id + 1, id - 4 * n + 3);
                if (j > 1) merge(id + 2, id);
            }
        }
        unordered_set<int> res;
        for (int i = 1; i <= 4 * m * n; i++) res.insert(findp(i));
        return res.size();
    }
};
