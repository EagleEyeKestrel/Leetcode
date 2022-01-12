//
//  main.cpp
//  首先肯定是拿到最大的k个数。关键就是按顺序返回
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        vector<int> v = nums;
        sort(nums.begin(), nums.end(), greater<int>());
        map<int, int> mp;
        for (int i = 0; i < k; i++) mp[nums[i]]++;
        for (int i = 0; i < n; i++) {
            if (mp[v[i]] > 0) {
                res.push_back(v[i]);
                mp[v[i]]--;
            }
        }
        return res;
    }
};
