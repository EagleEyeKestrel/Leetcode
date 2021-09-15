//
//  main.cpp
//  nlogn求二维LIS问题裸题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int n = height.size();
        pair<int, int> v[n];
        for (int i = 0; i < n; i++) v[i] = {height[i], weight[i]};
        sort(v, v + n, [](auto &pa, auto &pb) {
            if (pa.first == pb.first) return pa.second < pb.second;
            return pa.first > pb.first;
        });
        int dp[n];
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (sz == 0 || v[i].second < dp[sz - 1]) {
                dp[sz] = v[i].second;
                sz++;
            } else {
                int l = 0, r = sz - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (dp[mid] > v[i].second) l = mid + 1;
                    else r = mid;
                }
                dp[l] = v[i].second;
            }
        }
        return sz;
    }
};
