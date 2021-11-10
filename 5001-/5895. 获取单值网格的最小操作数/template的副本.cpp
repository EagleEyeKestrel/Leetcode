//
//  main.cpp
//  老题了，都变成中位数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int target = v[(v.size() - 1) / 2];
        int res = 0;
        for (int val: v) {
            int d = abs(val - target);
            if (d % x) return -1;
            res += d / x;
        }
        return res;
    }
};
