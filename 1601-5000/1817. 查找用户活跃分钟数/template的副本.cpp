//
//  main.cpp
//  考察STL的基本运用。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);
        unordered_map<int, unordered_set<int>> mp;
        for (auto &log: logs) {
            mp[log[0]].insert(log[1]);
        }
        for (auto it: mp) {
            int sz = it.second.size();
            res[sz - 1]++;
        }
        return res;
    }
};
