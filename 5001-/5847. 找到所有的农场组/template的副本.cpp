//
//  main.cpp
//  比较简单，朴素查找一下，既然都是矩形，找到之后直接重置为0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int m = land.size(), n = land[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j;
                    int r2 = r1, c2 = c1;
                    while (r2 + 1 < m && land[r2 + 1][c1] == 1) r2++;
                    while (c2 + 1 < n && land[r1][c2 + 1] == 1) c2++;
                    res.push_back({r1, c1, r2, c2});
                    for (int ii = r1; ii <= r2; ii++) {
                        for (int jj = c1; jj <= c2; jj++) {
                            land[ii][jj] = 0;
                        }
                    }
                }
            }
        }
        return res;
    }
};
