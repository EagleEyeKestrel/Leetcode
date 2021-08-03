//
//  main.cpp
//  简单的遍历
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int l, int r, int dist) {
        if (r - l <= dist) return 0;
        int d = r - l;
        if (d % dist == 0) return d / dist - 1;
        return d / dist;
    }
    int addRungs(vector<int>& rungs, int dist) {
        int res = 0;
        rungs.insert(rungs.begin(), 0);
        for (int i = 0; i < rungs.size() - 1; i++) res += f(rungs[i], rungs[i + 1], dist);
        return res;
    }
};
