//
//  main.cpp
//  遍历两次就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int l = 1, r = 1;
        for(int i = 1; i < n; i++) {
            l *= nums[i - 1];
            res[i] *= l;
        }
        for(int i = n - 2; i >= 0; i--) {
            r *= nums[i + 1];
            res[i] *= r;
        }
        return res;
    }
};
