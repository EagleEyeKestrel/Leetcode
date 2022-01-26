//
//  main.cpp
//  贪心，争取赠送最大的糖果
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0, n = cost.size(), i = n - 1;
        sort(cost.begin(), cost.end());
        while (i >= 2) {
            res += cost[i] + cost[i - 1];
            i -= 3;
        }
        while (i >= 0) {
            res += cost[i--];
        }
        return res;
    }
};