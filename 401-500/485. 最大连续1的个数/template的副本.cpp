//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tmp = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) tmp++;
            else tmp = 0;
            res = max(res, tmp);
        }
        return res;
    }
};
