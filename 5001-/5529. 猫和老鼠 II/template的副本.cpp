//
//  main.cpp
//  周赛出这种题真是硬核啊。。
//  参考了heyshb的解法，直接抄了一遍，dfs的写法，记忆化搜索
//  win第一维表示当前轮数，然后是mxmy,cxcy，最后一维表示当前是谁的轮
//  注意原题说的是1000轮，真正的搜索不可能这么多层，地图不超过64步，所以这里设置了70
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int m, n, cx, cy, mx, my, fx, fy, cj, mj;
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    int win[1010][8][8][8][8][2];
    int dfs(vector<string>& grid, int turn, int mx, int my, int cx, int cy, int who) {
        int &cache = win[turn][mx][my][cx][cy][who];
        if (cache) return cache;
        if (turn == 70) return 1;
        if (mx == fx && my == fy) return 2;
        if (cx == fx && cy == fy) return 1;
        if (cx == mx && cy == my) return 1;
        if (!who) {
            for (int dir = 0; dir < 4; dir++) {
                for (int i = 0; i <= mj; i++) {
                    int newx = mx + dx[dir] * i;
                    int newy = my + dy[dir] * i;
                    if (newx < 0 || newx >= m || newy < 0 || newy >= n) break;
                    if (grid[newx][newy] == '#') break;
                    if (dfs(grid, turn, newx, newy, cx, cy, 1) == 2) {
                        return cache = 2;
                    }
                }
            }
            return cache = 1;
        } else {
            for (int dir = 0; dir < 4; dir++) {
                for (int i = 0; i <= cj; i++) {
                    int newx = cx + dx[dir] * i;
                    int newy = cy + dy[dir] * i;
                    if (newx < 0 || newx >= m || newy < 0 || newy >= n) break;
                    if (grid[newx][newy] == '#') break;
                    if (dfs(grid, turn + 1, mx, my, newx, newy, 0) == 1) {
                        return cache = 1;
                    }
                }
            }
            return cache = 2;
        }
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        m = grid.size(), n = grid[0].size();
        cj = catJump;
        mj = mouseJump;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'C') cx = i, cy = j;
                if (grid[i][j] == 'M') mx = i, my = j;
                if (grid[i][j] == 'F') fx = i, fy = j;
            }
        }
        if (dfs(grid, 0, mx, my, cx, cy, 0) == 2) return true;
        return false;
    }
};
