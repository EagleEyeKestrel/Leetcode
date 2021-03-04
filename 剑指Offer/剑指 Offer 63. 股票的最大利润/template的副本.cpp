//
//  main.cpp
//  nowmin表示之前的最低价
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;
        int nowmin = prices[0], res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - nowmin);
            nowmin = min(prices[i], nowmin);
        }
        return res;
    }
};
