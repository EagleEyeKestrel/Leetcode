//
//  main.cpp
//  二分，每次和最后一个元素比较就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[n - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
