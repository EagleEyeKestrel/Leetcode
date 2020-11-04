//
//  main.cpp
//  分三段，主要是中间一段如何处理
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};
