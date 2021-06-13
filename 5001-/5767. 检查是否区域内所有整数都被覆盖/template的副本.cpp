//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int vis[51] = { 0 };
        for (auto &v: ranges) {
            for (int i = v[0]; i <= v[1]; i++) vis[i] = 1;
        }
        for (int i = left; i <= right; i++) {
            if (vis[i] == 0) return false;
        }
        return true;
    }
};
