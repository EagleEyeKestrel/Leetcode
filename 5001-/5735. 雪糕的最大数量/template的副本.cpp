//
//  main.cpp
//  贪心地从最便宜的开始买即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            if (coins < costs[i]) return i;
            coins -= costs[i];
        }
        return costs.size();
    }
};
