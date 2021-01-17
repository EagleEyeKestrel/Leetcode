//
//  main.cpp
//  都转化成数字，然后算间隔
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(), res = INT_MAX;
        int times[n];
        for (int i = 0; i < n; i++) {
            string tmp = timePoints[i];
            int m = 10 * (tmp[0] - '0') + tmp[1] - '0';
            int s = 10 * (tmp[3] - '0') + tmp[4] - '0';
            times[i] = 60 * m + s;
        }
        sort(times, times + n);
        for (int i = 0; i < n - 1; i++) {
            res = min(res, times[i + 1] - times[i]);
        }
        return min(res, times[0] + 1440 - times[n - 1]);
    }
};
