//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;
        int now = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i] == prices[i - 1] - 1) {
                now = now + 1;
            } else {
                now = 1;
            }
            res += now;
        }
        return res;
    }
};
