//
//  main.cpp
//  前缀和裸题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class NumArray {
public:
    int sum[10010];
    NumArray(vector<int>& nums) {
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
