//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = 0, n = nums.size();
        while (1) {
            if (res + start < n && nums[res + start] == target || start - res >= 0 && nums[start - res] == target)  return res;
            res++;
        }
        return -1;
    }
};
