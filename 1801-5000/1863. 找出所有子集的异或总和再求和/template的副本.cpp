//
//  main.cpp
//  最简单的状态压缩，穷举所有状态。不过居然是简单题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) tmp ^= nums[i];
            }
            res += tmp;
        }
        return res;
    }
};
