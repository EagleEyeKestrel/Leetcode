//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int d[n + 1];
        memset(d, 0, sizeof(d));
        for (auto &edge: edges) {
            d[edge[0]]++, d[edge[1]]++;
        }
        for (int i = 1; i <= n; i++) if (d[i] > 1) return i;
        return -1;
    }
};
