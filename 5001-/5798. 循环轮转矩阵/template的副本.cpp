//
//  main.cpp
//  周赛247卡了很久的一道题。。模拟题
//  首先一点，我一上来就习惯性写了k%=4，但其实每一个环 循环的次数都不一样，而且根本也不是4
//  对每一轮环然后依次模拟就行了。思路其实没什么好说的，还是要细致
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int m, n;
    void rotate(vector<vector<int>>& grid, int rounds) {
        for (int k = 0; k < min(m, n) / 2; k++) {
            int rounds_ = rounds % (2 * m + 2 * n - 4 * (2 * k + 1));
            for (int t = 0; t < rounds_; t++) {
                vector<vector<int>> v(m, vector<int>(n));
                for (int i = k + 1; i <= m - 1 - k; i++) v[i][k] = grid[i - 1][k];
                for (int j = k + 1; j <= n - 1 - k; j++) v[m - 1 - k][j] = grid[m - 1 - k][j - 1];
                for (int i = k; i <= m - 2 - k; i++) v[i][n - 1 - k] =grid[i + 1][n - 1 - k];
                for (int j = k; j <= n - 2 - k; j++) v[k][j] = grid[k][j + 1];

                for (int i = k + 1; i <= m - 1 - k; i++) grid[i][k] = v[i][k];
                for (int j = k + 1; j <= n - 1 - k; j++) grid[m - 1 - k][j] = v[m - 1 - k][j];
                for (int i = k; i <= m - 2 - k; i++) grid[i][n - 1 - k] = v[i][n - 1 - k];
                for (int j = k; j <= n - 2 - k; j++) grid[k][j] = v[k][j];
            }

        }

    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        rotate(grid, k);
        return grid;
    }
};
