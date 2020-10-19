//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), now = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                nums[now++] = nums[i];
            }
        }
        for(int i = now; i < n; i++) nums[i] = 0;
    }
};
