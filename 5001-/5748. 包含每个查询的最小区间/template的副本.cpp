//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/116360310
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = queries.size(), n = intervals.size();
        vector<int> q;
        for (int i = 0; i < m; i++) q.push_back(i);
        sort(q.begin(), q.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });
        vector<int> res(m);
        sort(intervals.begin(), intervals.end());
        set<pair<int, int>> s;
        int id = -1;
        for (int i = 0; i < m; i++) {
            while (id + 1 < n && intervals[id + 1][0] <= queries[q[i]]) {
                id++;
                s.insert({ intervals[id][1] - intervals[id][0] + 1, intervals[id][1] });
            }
            while (!s.empty() && s.begin()->second < queries[q[i]]) s.erase(s.begin());
            if (s.empty()) res[q[i]] = -1;
            else res[q[i]] = s.begin()->first;
        }
        return res;
    }
};
