//
//  main.cpp
//  二分
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        int res1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] != target) return 0;
        res1 = l;
        l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        return l - res1 + 1;
    }
};
