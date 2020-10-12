//
//  main.cpp
//  如果是比赛，直接暴力肯定方便。
//  平时的话，既然是会被右边第一个小于等于的值弹出，那就是典型的单调栈
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && prices[s.top()] >= prices[i]) {
                res[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            res[s.top()] = prices[s.top()];
            s.pop();
        }
        return res;
    }
};
