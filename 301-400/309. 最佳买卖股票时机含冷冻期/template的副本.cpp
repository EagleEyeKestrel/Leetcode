//
//  main.cpp
//  O(n)空间，hold/free表示第i天持有/没有股票的最大利润
//  不同之处在于hold[i]的转移方程变成了free[i-2]
//  显然可以做到空间O(1)，free[i-2]可以用free_pre存一下。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int hold[n + 1], free[n + 1];
        hold[0] = -prices[0];
        free[0] = 0;
        hold[1] = max(-prices[0], -prices[1]);
        free[1] = max(0, prices[1] - prices[0]);
        for(int i = 2;i < n;i++) {
            hold[i] = max(hold[i - 1], free[i - 2] - prices[i]);
            free[i] = max(free[i - 1], hold[i - 1] + prices[i]);
        }
        return free[n - 1];
    }
};
