//
//  main.cpp
//  交换，之前应该有过这道题的，把数字放在相应的位置上，那不在相应位置上的数字就肯定是重复了
//  或者用负数标记法
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[nums[i]] != nums[i]) swap(nums[nums[i]], nums[i]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) return nums[i];
        }
        return 0;
    }
};
