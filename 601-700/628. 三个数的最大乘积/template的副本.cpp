//
//  main.cpp
//  要么是最大的三个数乘积，要么是最大的乘以两个最小的
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int v1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int v2 = nums[0] * nums[1] * nums[n - 1];
        return max(v1, v2);
    }
};
