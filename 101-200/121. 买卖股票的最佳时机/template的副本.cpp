//
//  main.cpp
//  第一则问题比较简单，直接记录之前的最小值，相减，取最大值即可
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int nowmin = prices[0], res = 0;
        for(int i = 1; i < n; i++) {
            res = max(res, prices[i] - nowmin);
            nowmin = min(prices[i], nowmin);
        }
        return res;
    }
};
