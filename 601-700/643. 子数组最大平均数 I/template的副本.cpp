//
//  main.cpp
//  其实就是找长度为k，元素和最大的滑动窗口
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }
};
