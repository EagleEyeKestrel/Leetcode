//
//  main.cpp
//  也是类似双指针的题。可以看到时间限制是O(n2)的
//  排序之后对于一个nums[i]作为最左边的值，可以用双指针遍历nums[l], nums[r]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), resDiff = INT_MAX, resSum;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target - nums[i]) return target;
                if (nums[l] + nums[r] + nums[i] < target) {
                    if (target - (nums[l] + nums[r] + nums[i]) < resDiff) {
                        resSum = nums[l] + nums[r] + nums[i];
                        resDiff = target - resSum;
                    }
                    l++;
                } else {
                    if (nums[l] + nums[r] + nums[i] - target < resDiff) {
                        resSum = nums[l] + nums[r] + nums[i];
                        resDiff = resSum - target;
                    }
                    r--;
                }
            }
        }
        return resSum;
    }
};
