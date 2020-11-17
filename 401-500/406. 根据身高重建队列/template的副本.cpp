//
//  main.cpp
//  n^2就可以了
//  按身高从大到小排序，那么就可以依次插入了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> res;
        for(auto &v: people) {
            res.insert(res.begin() + v[1], v);
        }
        return res;
    }
};
