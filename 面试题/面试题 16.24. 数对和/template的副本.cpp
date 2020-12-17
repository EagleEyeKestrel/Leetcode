//
//  main.cpp
//  双指针 裸题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l = 0, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) l++;
            else if (nums[l] + nums[r] > target) r--;
            else {
                res.push_back({ nums[l], nums[r] });
                l++, r--;
            }
        }
        return res;
    }
};
