//
//  main.cpp
//  题目没说是非递减序列，其实是非递减的。。
//  可以二分剪枝，或者像下面这样跳跃
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == i) return i;
            i = max(i, nums[i] - 1);
        }
        return -1;
    }
};
