//
//  main.cpp
//  滑动窗口裸题
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, nowprod = 1, res = 0;
        for(int r = 0; r < n; r++) {
            nowprod *= nums[r];
            while(nowprod >= k && l <= r) {
                nowprod /= nums[l];
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};
