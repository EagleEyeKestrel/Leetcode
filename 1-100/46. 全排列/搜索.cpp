//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            f(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums, 0);
        return res;
    }
};