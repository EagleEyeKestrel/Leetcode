//
//  main.cpp
//  简单的双指针
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), l = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != val) {
                nums[l++] = nums[i];
            }
        }
        return l;
    }
};
