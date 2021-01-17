//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxl = 0, res = 0;
        for (auto &v: rectangles) {
            maxl = max(maxl, min(v[0], v[1]));
        }
        for (auto &v: rectangles) {
            if (min(v[0], v[1]) == maxl) res++;
        }
        return res;
    }
};
