//
//  main.cpp
//  差分，模版题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (auto &v: bookings) {
            res[v[0] - 1] += v[2];
            if (v[1] < n) res[v[1]] -= v[2];
        }
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }
        return res;
    }
};
