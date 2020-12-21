//
//  main.cpp
//  按区间左端点排序。对于[a,b] [c,d]，c >= a，
//  如果c > b，那么直接放在末尾，作为一个新的区间
//  否则，新区间为[a, max(b, d)]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto &v: intervals) {
            if (res.empty() || v[0] > res.back()[1]) {
                res.push_back(v);
            } else {
                res[res.size() - 1][1] = max(res[res.size() - 1][1], v[1]);
            }
        }
        return res;
    }
};
