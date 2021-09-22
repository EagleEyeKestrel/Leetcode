//
//  main.cpp
//  双指针固然也可以。这里暴力了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) res++;
            }
        }
        return res;
    }
};
