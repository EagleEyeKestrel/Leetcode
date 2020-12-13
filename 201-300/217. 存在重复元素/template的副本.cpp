//
//  main.cpp
//  解法很多，还可以哈希，等等
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};
