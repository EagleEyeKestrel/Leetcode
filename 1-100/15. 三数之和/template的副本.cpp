//
//  main.cpp
//  排序之后，穷举最左边的值，剩下的l r用双指针
//  关于重复，可以都用一种形式，如果nums[i]==nums[i-1] continue;
//  l和r双指针里面也可以，if nums[l]==nums[l-1]，l++,continue即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1, target = -nums[i];
            while (l < r) {
                while (l > i + 1 && l < n && nums[l] == nums[l - 1]) l++;
                while (r < n - 1 && r >= 0 && nums[r] == nums[r + 1]) r--;
                if (l >= r) break;
                if (nums[l] + nums[r] < target) l++;
                else if(nums[l] + nums[r] > target) r--;
                else {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    l++, r--;
                }
            }
        }
        return res;
    }
};
