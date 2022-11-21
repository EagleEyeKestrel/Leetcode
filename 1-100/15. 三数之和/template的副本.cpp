//
//  main.cpp
//  排序之后，穷举最大的值，剩下的l r用双指针
//  关键是处理重复，舍弃掉更小的情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 2; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1])
                continue;
            int target = -nums[i];
            int l = 0, r = i - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target || (r + 1 <= i - 1 && nums[r] == nums[r + 1])) {
                    r--;
                } else if (sum < target || (l - 1 >= 0 && nums[l] == nums[l - 1])) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }
        return res;
    }
};
