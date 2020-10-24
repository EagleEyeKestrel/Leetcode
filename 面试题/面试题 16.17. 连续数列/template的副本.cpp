//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), nowmin = 0, s = 0, res = INT_MIN;
        for(int i = 1; i <= n; i++) {
            s += nums[i - 1];
            res = max(res, s - nowmin);
            nowmin = min(nowmin, s);
        }
        return res;
    }
};
