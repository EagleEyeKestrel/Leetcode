//
//  main.cpp
//  滑动窗口裸题。。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), sum = 0, res = INT_MAX, l = 0;
        for(int r = 0; r < n; r++) {
            sum += nums[r];
            while(sum >= s) {
                res = min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
