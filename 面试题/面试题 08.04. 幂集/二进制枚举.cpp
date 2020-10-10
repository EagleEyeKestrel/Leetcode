//
//  main.cpp
//  二进制枚举法，相当于状态压缩
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < 1 << n; i++) {
            vector<int> tmp;
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1) {
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
