//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1, mind = 1e6;
        for (int i = 0; i < points.size(); i++) {
            auto point = points[i];
            if (point[0] == x || point[1] == y) {
                if (abs(x - point[0]) + abs(y - point[1]) < mind) {
                    mind = abs(x - point[0]) + abs(y - point[1]);
                    res = i;
                }
            }
        }
        return res;
    }
};
