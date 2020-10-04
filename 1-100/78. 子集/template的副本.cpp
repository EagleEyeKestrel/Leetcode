//
//  main.cpp
//  方法很多。。dfs, 然后位运算法，bit向量法
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int i, int n, vector<int>& tmp) {
        res.push_back(tmp);
        for(int j = i; j < n; j++) {
            tmp.push_back(nums[j]);
            dfs(nums, j+1, n, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        dfs(nums, 0, n, tmp);
        return res;
    }
};
