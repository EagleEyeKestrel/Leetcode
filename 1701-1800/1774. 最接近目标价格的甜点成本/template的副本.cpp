//
//  main.cpp
//  数据规模非常小，可以dfs或者枚举子集，3^10 * 10 * 10
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size(), res = baseCosts[0];
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << m); mask++) {
                for (int sub = mask; ; sub = (sub - 1) & mask) {
                    int tmp = baseCosts[i];
                    for (int j = 0; j < m; j++) {
                        if ((mask >> j) & 1) tmp += toppingCosts[j];
                        if ((sub >> j) & 1) tmp += toppingCosts[j];
                    }
                    if (abs(target - tmp) < abs(res - target) || abs(target - tmp) == abs(res - target) && tmp < res) res = tmp;
                    if (sub == 0) break;
                }
            }
        }
        return res;
    }
};
