//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) if(nums[i] == nums[j]) res++;
        }
        return res;
    }
};
