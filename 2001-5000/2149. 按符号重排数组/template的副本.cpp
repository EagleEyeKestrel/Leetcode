//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), i = 0, j = 0;
        for (int k = 0; k < n / 2; k++) {
            while (nums[i] <= 0) i++;
            while (nums[j] >= 0) j++;
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            i++, j++;
        }
        return res;
    }
};