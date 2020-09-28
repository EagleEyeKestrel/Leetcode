//
//  main.cpp
//  和之前的简单的无限次交易相比，就是多了个手续费。用hold/free表示当前如果持有/没有股票的最大利润
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -1e6, free = 0;
        for(int i = 1; i <= n; i++) {
            int oldfree = free, oldhold = hold;
            free = max(oldfree, oldhold + prices[i - 1] - fee);
            hold = max(oldhold, oldfree - prices[i - 1]);
        }
        return free;
    }
};
