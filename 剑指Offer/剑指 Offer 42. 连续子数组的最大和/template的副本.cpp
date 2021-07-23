//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), minv = 0, res = INT_MIN, s = 0;
        for (int num: nums) {
            s += num;
            res = max(res, s - minv);
            minv = min(minv, s);
        }
        return res;
    }
};
