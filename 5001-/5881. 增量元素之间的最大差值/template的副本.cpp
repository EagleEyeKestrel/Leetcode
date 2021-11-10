//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) res = max(res, nums[j] - nums[i]);
            }
        }
        return res;
    }
};
