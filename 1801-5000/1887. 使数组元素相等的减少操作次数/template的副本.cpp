//
//  main.cpp
//  每个元素的操作次数其实就是，排序去重之后每个元素的索引
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        auto pos = unique(v.begin(), v.end());
        int l = pos - v.begin();
        unordered_map<int, int> mp;
        for (int i = 0; i < l; i++) {
            mp[v[i]] = i;
        }
        for (int num: nums) {
            res += mp[num];
        }
        return res;
    }
};
