//
//  main.cpp
//  sort之后双指针
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        int l = 0;
        for(int r = 0; r < n; r++) {
            while(r < n - 1 && nums[r + 1] == nums[r]) r++;
            while(l < r - 1 && nums[l + 1] <= nums[r] - k) l++;
            if(nums[l] == nums[r] - k && l < r) {
                res++;
            }
            while(l < r && nums[l] == nums[l + 1]) l++;
        }
        return res;
    }
};
