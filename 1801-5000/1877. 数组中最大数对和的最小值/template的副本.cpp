//
//  main.cpp
//  直觉上肯定是排序，可以使得最大数对和最小，最小数对和最大
//  证明可以去看看题解
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};
