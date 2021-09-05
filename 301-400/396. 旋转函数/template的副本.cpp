//
//  main.cpp
//  比较简单，算下每两次之间的差就好了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, s = 0;
        for (int i = 0; i < n; i++) sum += i * nums[i], s += nums[i];
        int res = sum, last = sum;
        for (int i = 1; i < n; i++) {
            last = last - (n - 1) * nums[n - i] + s - nums[n - i];
            res = max(res, last);
        }
        return res;
    }
};
