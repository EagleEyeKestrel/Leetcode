//
//  main.cpp
//  写在注释了。当然j也可以表示最多进行j次交易，那么dpi10, dpi20应该初始化为0， 最后直接return dpi20即可
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    //  dp i j k表示前i天，完成了j次交易，k表示是否持有股票
    //  dp[i][0][1] = max(-prices[i], dp[i - 1][0][1]);
    //  dp[i][1][0] = max(dp[i - 1][0][1] + prices[i], dp[i - 1][1][0]);
    //  dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] - prices[i]);
    //  dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] + prices[i]);
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long dpi01 = INT_MIN, dpi10 = INT_MIN, dpi11 = INT_MIN, dpi20 = INT_MIN;
        for(int price: prices) {
            dpi20 = max(dpi20, dpi11 + price);
            dpi11 = max(dpi11, dpi10 - price);
            dpi10 = max(dpi10, dpi01 + price);
            dpi01 = max(dpi01, (long)-price);
        }
        return max(0, (int)max(dpi10, dpi20));
    }
};
