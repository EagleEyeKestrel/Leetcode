//
//  main.cpp
//  穷举坐标就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double dist(int x1, int y1, int x2, int y2) {
        int dx = x1 - x2, dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> res = {-1, -1};
        int maxv = -1;
        for(int i = -50; i <= 100; i++) {
            for(int j = -50; j <= 100; j++) {
                int tmp = 0;
                for(auto &t: towers) {
                    double d = dist(t[0], t[1], i, j);
                    if(d <= radius) {
                        tmp += (int)(t[2] / (d + 1));
                    }
                }
                if(tmp > maxv) {
                    maxv = tmp;
                    res = {i, j};
                }
            }
        }
        return res;
    }
};
