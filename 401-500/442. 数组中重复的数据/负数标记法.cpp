//
//  main.cpp
//  因为元素的范围是确定的，把出现过的元素，对应位置标记成负数。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] *= (-1);
        }
        return res;
    }
};
