//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0, maxv = 0, minv = 1e9;
        int n = salary.size();
        for(int x: salary) {
            maxv = max(maxv, (double)x);
            minv = min(minv, (double)x);
            sum += x;
        }
        return (sum - minv - maxv) / (n - 2);
    }
};
