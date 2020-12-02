//
//  main.cpp
//  二分，只不过两次的条件不一样。一次是找第一个，一次是找最后一个，注意每次l和r更新的变化
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(!n || nums[l] != target) return {-1, -1};
        int res1 = l;
        l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return {res1, l};
    }
};
