//
//  main.cpp
//  说实话虽然是简单题，但这个最好的解法我还真没想到。
//  我想的还是通过k去模n来看
//  但本质上，一次操作就是对应的一维数组向右移一格
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int res[m * n], Res[m * n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i * n + j] = grid[i][j];
            }
        }
        for(int i = 0; i < m * n; i++) Res[(i + k) % (m * n)] = res[i];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = Res[i * n + j];
            }
        }
        return grid;
    }
};
