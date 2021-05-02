//
//  main.cpp
//  比较简单，就是看每一行的前缀和，出现最多次数的地方。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), maxv = 0;
        unordered_map<int, int> mp;
        for (auto &v: wall) {
            int s = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                s += v[i];
                mp[s]++;
            }
        }
        for (auto it: mp) maxv = max(maxv, it.second);
        return n - maxv;
    }
};
