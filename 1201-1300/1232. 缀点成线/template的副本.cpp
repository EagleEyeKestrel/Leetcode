//
//  main.cpp
//  化简斜率相等的式子，变成整式
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n < 3) return true;
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - coordinates[0][0]) * (coordinates[1][1] - coordinates[0][1]) != (y - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0])) return false;
        }
        return true;
    }
};
