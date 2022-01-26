//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long maxv = -1e18, minv = 1e18, tmp = 0;
        for (int x: differences) {
            tmp += x;
            maxv = max(maxv, tmp);
            minv = min(minv, tmp);
        }
        //a+maxv<=upper a <= upper-maxv
        //a+minv>=lower a >= lower-minv
        //a >= lower, a <= upper
        long long L = max((long long)lower, lower - minv);
        long long R = min((long long)upper, upper - maxv);
        return R >= L ? R - L + 1 : 0;
    }
};