//
//  main.cpp
//  贪心，如果比上个数小，就每次变成上个数+1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                res += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};
