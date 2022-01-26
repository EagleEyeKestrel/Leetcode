//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1] || i < n - 1 && nums[i] == nums[i + 1]) continue;
            if (i > 0 && nums[i - 1] == nums[i] - 1 || i < n - 1 && nums[i + 1] == nums[i] + 1) continue;
            res.push_back(nums[i]);
        }
        return res;
    }
};