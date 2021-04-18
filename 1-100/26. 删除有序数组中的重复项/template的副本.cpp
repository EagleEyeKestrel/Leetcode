//
//  main.cpp
//  最基础的双指针
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), p1 = 0;
        for (int p2 = 0; p2 < n; p2++) {
            if (!p2 || nums[p2] != nums[p2 - 1]) nums[p1++] = nums[p2];
        }
        return p1;
    }
};
