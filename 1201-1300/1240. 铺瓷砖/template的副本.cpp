//
//  main.cpp
//  暴力搜索，找到第一个空缺位置，然后穷举放的正方形边长，放下之后再继续搜索
//  注意l要从大到小进行枚举，方便剪枝
//  但是据说当nm较大的时候这种解法是错的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int grid[14][14];
    int res = INT_MAX;
    void dfs(int n, int m, int depth) {
        if (depth >= res) return;
        int full = 1, r, c;
        for (int i = 1; i <= n && full; i++) {
            for (int j = 1; j <= m && full; j++) {
                if (grid[i][j] == 0) {
                    r = i, c = j;
                    full = 0;
                    break;
                }
            }
        }
        if (full) {
            res = min(res, depth);
            return;
        }
        for (int l = min(n - r + 1, m - c + 1); l >= 1; l--) {
            int haveTile = 0;
            for (int i = r; i <= r + l - 1 && !haveTile; i++) {
                for (int j = c; j <= c + l - 1; j++) {
                    if (grid[i][j]) {
                        haveTile = 1;
                        break;
                    }
                }
            }
            if (haveTile) continue;
            for (int i = r; i <= r + l - 1 && !haveTile; i++) {
                for (int j = c; j <= c + l - 1; j++) {
                    grid[i][j] = 1;
                }
            }
            dfs(n, m, depth + 1);
            for (int i = r; i <= r + l - 1 && !haveTile; i++) {
                for (int j = c; j <= c + l - 1; j++) {
                    grid[i][j] = 0;
                }
            }
        }
    }
    int tilingRectangle(int n, int m) {
        memset(grid, 0, sizeof(grid));
        dfs(n, m, 0);
        return res;
    }
};
