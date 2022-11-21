//
//  main.cpp
//  没太大意义的题目，没什么算法，就是容易错
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return k % 2 ? -1 : nums[0];
        }
        int mx[n];
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], nums[i]);
        if (k <= 1) return nums[k];
        if (k > 1 && k < n) {
            return max(mx[k - 2], nums[k]);
        }
        if (k == n) {
            return mx[n - 2];
        }
        return mx[n - 1];
    }
};