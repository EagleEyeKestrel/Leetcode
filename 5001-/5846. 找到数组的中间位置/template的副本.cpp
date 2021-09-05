//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        for (int mid = 0; mid < n; mid++) {
            int s1 = 0, s2 = 0;
            for (int i = 0; i < mid; i++) s1 += nums[i];
            for (int i = mid + 1; i < n; i++) s2 += nums[i];
            if (s1 == s2) return mid;
        }
        return -1;
    }
};
