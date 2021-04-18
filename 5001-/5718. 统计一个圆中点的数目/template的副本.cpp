//
//  main.cpp
//  穷举即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto &q: queries) {
            int x = q[0], y = q[1], r = q[2], cnt = 0;
            for (auto &p: points) {
                if ((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]) <= r * r) {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};
