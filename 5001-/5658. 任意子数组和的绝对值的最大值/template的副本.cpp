//
//  main.cpp
//  换成绝对值了，原来求最大子数组只需要记录之前前缀和的最小值，现在还需记录一下最大值
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
