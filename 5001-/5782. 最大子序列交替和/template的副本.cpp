//
//  main.cpp
//  简单的dp，用odd[i]表示前i个元素，选取长度为奇数的子序列，最大的交替和，even表示偶数长度的子序列
//  当然可以优化空间到O(1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        long long odd[n], even[n];
        odd[0] = nums[0];
        even[0] = 0;
        for (int i = 1; i < n; i++) {
            odd[i] = max(nums[i] + even[i - 1], odd[i - 1]);
            even[i] = max(odd[i - 1] - nums[i], even[i - 1]);
        }
        return max(odd[n - 1], even[n - 1]);
    }
};
