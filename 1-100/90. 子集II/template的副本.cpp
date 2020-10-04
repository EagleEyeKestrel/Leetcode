//
//  main.cpp
//  先排序没什么问题。要不重复的子集，(子集的元素可以重复)
//  那么对于重复的元素，dfs只遍历第一个就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int i, int n, vector<int>& tmp) {
        if(i >= n) {
            res.push_back(tmp);
            return ;
        }
        res.push_back(tmp);
        for(int j = i; j < n; j++) {
            tmp.push_back(nums[j]);
            dfs(nums, j+1, n, tmp);
            tmp.pop_back();
            while(j + 1 < n && nums[j+1] == nums[j]) j++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, 0, n, tmp);
        return res;
    }
};
