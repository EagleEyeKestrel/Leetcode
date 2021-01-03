//
//  main.cpp
//  第一次发现这种蛇型问题，用排序可以非常简单！
//  开始真没想到啊
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < nums[i].size(); j++) v.push_back({ i, j });
        }
        sort(v.begin(), v.end(), [&nums](auto &a, auto &b) {
            if (a.first + a.second == b.first + b.second) return a.first > b.first;
            return a.first + a.second < b.first + b.second;
        });
        vector<int> res;
        for (auto &tmp: v) res.push_back(nums[tmp.first][tmp.second]);
        return res;
    }
};
