//
//  main.cpp
//  善用sort
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>& v2) {
            return (long)v1[0] * v1[0] + (long)v1[1] * v1[1] < (long)v2[0] * v2[0] + (long)v2[1] * v2[1];
        });
        vector<vector<int>> res;
        for(int i = 0; i < K; i++) res.push_back(points[i]);
        return res;
    }
};
