//
//  main.cpp
//  构造形如 1 n 2 n-1。。。这样的序列即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0, j = n - 1;
        while (i < j) {
            res.push_back(nums[i++]);
            res.push_back(nums[j--]);
        }
        if (i == j) res.push_back(nums[i]);
        return res;
    }
};
