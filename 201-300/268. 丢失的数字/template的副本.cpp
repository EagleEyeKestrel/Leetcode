//
//  main.cpp
//  巧妙利用异或
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            res ^= nums[i];
            res ^= (i + 1);
        }
        return res;
    }
};
