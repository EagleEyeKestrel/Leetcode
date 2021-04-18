//
//  main.cpp
//  先找到最开始的k。然后每次消失了nums[i],k变成k^nums[i]即可，这样异或的结果不变
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), tmp = 0, k = -1, maxv = -1;
        vector<int> res(n);
        for (int num: nums) tmp ^= num;
        for (int i = 0; i < (1 << maximumBit); i++) {
            if ((i ^ tmp) > maxv) {
                maxv = i ^ tmp;
                k = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            res[n - 1 - i] = k;
            k ^= nums[i];
        }
        return res;
    }
};
