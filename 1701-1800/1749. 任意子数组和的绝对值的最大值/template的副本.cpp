//
//  main.cpp
//  绝对值最大值，那么就只需要求个最大值、最小值，再比比谁绝对值最大即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), res = 0, s = 0;
        int minv = 0, maxv = 0;
        for (int i = 1; i <= n; i++) {
            s += nums[i - 1];
            int v1 = abs(s - minv);
            int v2 = abs(s - maxv);
            res = max(res, max(v1, v2));
            minv = min(minv, s);
            maxv = max(maxv, s);
        }
        return res;
    }
};
