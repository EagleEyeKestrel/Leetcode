//
//  main.cpp
//  全放进去，然后自定义排序
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), [r0, c0](vector<int> &a, vector<int> &b) {
            int d1 = abs(a[0] - r0) + abs(a[1] - c0);
            int d2 = abs(b[0] - r0) + abs(b[1] - c0);
            return d1 < d2;
        });
        return res;
    }
};
