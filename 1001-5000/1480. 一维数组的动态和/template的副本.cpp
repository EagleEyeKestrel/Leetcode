//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> s;
        int n = nums.size(), nowSum = 0;
        for(int i = 0; i < n; i++) {
            nowSum += nums[i];
            s.push_back(nowSum);
        }
        return s;
    }
};
