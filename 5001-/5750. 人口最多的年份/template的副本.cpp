//
//  main.cpp
//  差分模版题，当然这题作为周赛第一题穷举也能过了。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size(), maxv = 0, res;
        int a[2100];
        memset(a, 0, sizeof(a));
        for (auto &log: logs) {
            a[log[0]]++;
            a[log[1]]--;
        }
        for (int i = 1; i < 2100; i++) {
            a[i] += a[i - 1];
            if (a[i] > maxv) {
                res = i;
                maxv = a[i];
            }
        }
        return res;
    }
};
