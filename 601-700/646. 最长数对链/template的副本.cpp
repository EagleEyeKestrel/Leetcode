//
//  main.cpp
//  活动安排问题裸题，经典的贪心问题，按照结束时间排序，然后贪心
//  当然dp也可以，但是就变成O(n^2)了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), res = 0, nowEnd = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        for(int i = 0; i < n; i++) {
            if(pairs[i][0] > nowEnd) {
                res++;
                nowEnd = pairs[i][1];
            }
        }
        return res;
    }
};
