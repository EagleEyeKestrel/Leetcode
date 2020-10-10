//
//  main.cpp
//  dfs法
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>>  res;
    void dfs(int i, vector<int>& tmp, int n, vector<int>& nums) {
        res.push_back(tmp);
        if(i >= n) return ;
        for(int j = i; j < n; j++) {
            tmp.push_back(nums[j]);
            dfs(j + 1, tmp, n, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        dfs(0, tmp, n, nums);
        return res;
    }
};
