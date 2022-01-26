//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[0] && nums[i] != nums.back()) res++;
        }
        return res;
    }
};