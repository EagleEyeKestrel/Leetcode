//
//  main.cpp
//  最基础的dp问题之一
//  now表示当前前缀和，minpre表示之前最小的前缀和。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), now = 0, minpre = 0, res = INT_MIN;
        for(int i = 0; i < n; i++) {
            now += nums[i];
            res = max(res, now - minpre);
            minpre = min(minpre, now);
        }
        return res;
    }
};
