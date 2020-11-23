//
//  main.cpp
//  贪心，按结束端点排序，然后每次从结束端点射
//  因为坐标范围任意，所以这里last弄了个long
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        long last = (long)INT_MIN - 1;
        int res = 0, n = points.size();
        for(int i = 0; i < n; i++) {
            if(!(last >= points[i][0] && last <= points[i][1])) {
                last = points[i][1];
                res++;
            }
        }
        return res;
    }
};
