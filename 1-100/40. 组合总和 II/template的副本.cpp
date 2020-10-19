//
//  main.cpp
//  关键就是怎么处理重复，当选择j的时候，重复的数字只选择第一个，后面的直接跳过
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    vector<vector<int>> res;
    void dfs(int i, vector<int>& tmp, int target, vector<int>& candidates) {
        if(target == 0) {
            res.push_back(tmp);
            return ;
        }
        for(int j = i; j < n; j++) {
            if(j > i && candidates[j] == candidates[j - 1]) continue;
            if(candidates[j] <= target) {
                tmp.push_back(candidates[j]);
                dfs(j + 1, tmp, target - candidates[j], candidates);
                tmp.pop_back();
            } else {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        vector<int> tmp;
        dfs(0, tmp, target, candidates);
        return res;
    }
};
