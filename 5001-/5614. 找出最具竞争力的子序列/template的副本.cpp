//
//  main.cpp
//  其实第一眼就看出这是n位数删n-k位的 单调栈 问题，但不相信第二题有这么难
//  想了想，也没想到什么其他好办法
//  要注意res.size() > k的时候，要取前k个数，WA了一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int rest = n - k;
        for(int i = 0; i < n; i++) {
            while(rest > 0 && !res.empty() && res.back() > nums[i]) {
                rest--;
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        if(res.size() > k) {
            res = vector<int>(res.begin(), res.begin() + k);
        }
        return res;
    }
};
