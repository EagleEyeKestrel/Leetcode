//
//  main.cpp
//  经典的回溯，search搜索第depth行，check检查某个位置是否可行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int grid[20][20];
    int res = 0;
    int check(int i, int j, int n) {
        for(int ii = 0; ii < i; ii++) {
            for(int jj = 0; jj < n; jj++) {
                if(grid[ii][jj] && (jj == j || ii - jj == i - j || ii + jj == i + j)) {
                    return 0;
                }
            }
        }
        return 1;
    }
    void search(int depth, int n) {
        if(depth == n) {
            res++;
            return;
        }
        for(int j = 0; j < n; j++) {
            if(check(depth, j, n)) {
                grid[depth][j] = 1;
                search(depth + 1, n);
                grid[depth][j] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        memset(grid, 0, sizeof(grid));
        search(0, n);
        return res;
    }
};
