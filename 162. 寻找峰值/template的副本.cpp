//
//  main.cpp
//  比较一下nums[mid]和nums[mid+1]就行啦
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
