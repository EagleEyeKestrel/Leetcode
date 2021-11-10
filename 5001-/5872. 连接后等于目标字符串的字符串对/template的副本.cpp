//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                string s = nums[i] + nums[j];
                if (s == target) res++;
            }
        }
        return res;
    }
};
