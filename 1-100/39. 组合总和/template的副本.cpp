//
//  main.cpp
//  经典的dfs，把candidates排个序，i表示从i索引开始选，left是和还差多少，tmp是当前的数组
//  边界条件就是left == 0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    void dfs(vector<int>& candidates, int i, int left, vector<vector<int>>& res, vector<int>& tmp) {
        if(!left) {
            res.push_back(tmp);
            return ;
        }
        for(int j = i; j < n; j++) {
            if(candidates[j] <= left) {
                tmp.push_back(candidates[j]);
                dfs(candidates, j, left - candidates[j], res, tmp);
                tmp.pop_back();
            } else {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        vector<int> tmp;
        dfs(candidates, 0, target, res, tmp);
        return res;
    }
};
