//
//  main.cpp
//  把i放到索引为i - 1的位置上。最后不在位置上的就是重复的。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
