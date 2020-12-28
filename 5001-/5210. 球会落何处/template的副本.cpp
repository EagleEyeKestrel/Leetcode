//
//  main.cpp
//  模拟题？我用dir表示进来的方向，2向下，1向左，3向右，change是grid内容
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int dir, int change) {
        if (change == 1) {
            if (dir == 2) dir++;
            else if (dir == 3) dir--;
            else if (dir == 1) dir = -1;
        } else {
            if (dir == 2) dir--;
            else if (dir == 1) dir++;
            else if (dir == 3) dir = -1;
        }
        return dir;
    }
    int run(vector<vector<int>>& grid, int j) {
        int dir = 2, i = 0, m = grid.size(), n = grid[0].size();
        while (i < m && j >= 0 && j < n) {
            int newdir = f(dir, grid[i][j]);
            if (newdir == -1) break;
            if (newdir == 1) {
                j--;
            } else if (newdir == 2) {
                i++;
            } else if (newdir == 3) {
                j++;
            }
            dir = newdir;
        }
        return i == m ? j : -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        for (int j = 0; j < n; j++) {
            res.push_back(run(grid, j));
        }
        return res;
    }
};
