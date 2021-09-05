//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i + k - 1 < n; i++) {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};
