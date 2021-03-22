//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), res = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (!i || nums[i] <= nums[i - 1]) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            res = max(res, tmp);
        }
        return res;
    }
};
