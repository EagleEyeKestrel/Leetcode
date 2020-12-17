//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), tmp = 1, res = 1;
        if (n < 2) return n;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                tmp++;
                res = max(res, tmp);
            } else {
                tmp = 1;
            }
        }
        return res;
    }
};
