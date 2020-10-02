//
//  main.cpp
//  up[i], down[i]表示i之前，最后一次是上升/下降的摆动序列的最长长度
//  当然可以把空间也优化到O（1）
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 1;
        if(!n) return 0;
        int up[n], down[n];
        up[0] = 1, down[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
            res = max(res, max(up[i], down[i]));
        }
        return res;
    }
};
