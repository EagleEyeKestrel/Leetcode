//
//  main.cpp
//  要注意题目有个意思可能容易误解，是要大于等于其他数字(值不相同)的两倍
//  比如[3,3,3]，要输出0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxv = INT_MIN, maxpos = -1, n = nums.size(), flag = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxpos = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != maxv && maxv < (nums[i] << 1)) {
                flag = 0;
                break;
            }
        }
        return flag ? maxpos : -1;
    }
};
