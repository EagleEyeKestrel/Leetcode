//
//  main.cpp
//  第二则股票问题，也简单的，可以发现只要相邻两天能赚，就买
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
