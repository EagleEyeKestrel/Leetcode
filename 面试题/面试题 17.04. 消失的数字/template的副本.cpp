//
//  main.cpp
//  很巧妙的题，还真没想到。。通过异或操作，缺失的那个数字只出现了一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i] ^ (i + 1);
        }
        return res;
    }
};
