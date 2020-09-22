//
//  main.cpp
//  关键在于nums[mid] == nums[r]的情况。 这里这个mid可能在左半边，也有可能在右半边
//  首先这里不再是和nums[n - 1]比较了，因为等于的情况我们只能更新r
//  l < r，那么mid不等于r, 可以放心r-- (还有nums[mid]是最小值)
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};
