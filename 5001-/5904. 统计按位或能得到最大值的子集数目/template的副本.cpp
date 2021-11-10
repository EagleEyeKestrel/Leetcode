//
//  main.cpp
//  数据范围很小，并且最大的OR和也是确定的，所以直接穷举
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int x: nums) target |= x;
        int res = 0, n = nums.size();
        for (int mask = 0; mask < 1 << n; mask++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) tmp |= nums[i];
            }
            if (tmp == target) res++;
        }
        return res;
    }
};
