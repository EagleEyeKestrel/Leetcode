//
//  main.cpp
//  后来试了一下，是因为19行 看有没有maxv/2 不能用count！ 要用find
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        multiset<int> se;
        for (int x: changed) se.insert(x);
        if (changed.size() % 2) return {};
        while (!se.empty()) {
            int maxv = *(se.rbegin());
            se.erase(se.find(maxv));
            if (maxv % 2 || se.find(maxv / 2) == se.end()) return {};
            res.push_back(maxv / 2);
            se.erase(se.find(maxv / 2));
        }
        return res;
    }
};
