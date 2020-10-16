//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int id = i * n + j;
                res[id / c][id % c] = nums[i][j];
            }
        }
        return res;
    }
};
