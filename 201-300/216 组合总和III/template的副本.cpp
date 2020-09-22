//
//  main.cpp
//  暴力穷举下一个数就完事儿了。。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int i, int cnt, int sum, int k, int n) {
        if(cnt == k && sum == n) {
            res.push_back(tmp);
            return ;
        }
        for(int j = i; j <= 9; j++) {
            tmp.push_back(j);
            dfs(j + 1, cnt + 1, sum + j, k, n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        tmp = vector<int> ();
        dfs(1, 0, 0, k, n);
        return res;
    }
};
