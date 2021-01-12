//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for (auto &v: paths) {
            s.insert(v[0]);
        }
        for (auto &v: paths) {
            if (!s.count(v[1])) return v[1];
        }
        return "";
    }
};
