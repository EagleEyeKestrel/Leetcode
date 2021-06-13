//
//  main.cpp
//  最后一题略水。。双指针就能过，每次往大的数走
//  这题其实就是P84的变体，对每个数可以找到左边/右边第一个比他小的数，然后判断k在不在里面即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), res = nums[k], l = k - 1, r = k + 1, minv = nums[k];
        while (l >= 0 || r < n) {
            int v1 = l >= 0 ? nums[l] : INT_MIN;
            int v2 = r < n ? nums[r] : INT_MIN;
            int tmp = v1 >= v2 ? nums[l--] : nums[r++];
            minv = min(minv, tmp);
            res = max(res, minv * (r - l - 1));
        }
        return res;
    }
};
