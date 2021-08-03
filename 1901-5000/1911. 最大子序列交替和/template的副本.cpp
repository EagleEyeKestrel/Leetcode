//
//  main.cpp
//  dp，用odd[i]表示到nums[i]为止 取奇数个数 能获得的最大分数 even表示取偶数个 同理
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
