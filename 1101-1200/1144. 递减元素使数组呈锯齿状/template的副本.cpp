//
//  main.cpp
//  分两种情况讨论一下，每种情况只需要递减 应该处于锯齿低位的元素
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), res1 = 0, res2 = 0;
        for (int i = 1; i < n; i += 2) {
            if (nums[i] >= nums[i - 1] || i + 1 < n && nums[i] >= nums[i + 1]) {
                int d = min(nums[i - 1], i + 1 < n ? nums[i + 1] : INT_MAX);
                res1 += nums[i] - (d - 1);
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (i && nums[i] >= nums[i - 1] || i + 1 < n && nums[i] >= nums[i + 1]) {
                int d = min(i ? nums[i - 1] : INT_MAX, i + 1 < n ? nums[i + 1] : INT_MAX);
                res2 += nums[i] - (d - 1);
            }
        }
        return min(res1, res2);
    }
};
