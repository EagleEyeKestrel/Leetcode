//
//  main.cpp
//  比较tricky的方法
//  先开始就对 w l h排序。因为排序然后一一对应，是两个砖块堆叠的最优解。
//  然后让最大的数作为高，因为要高最大。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &v: cuboids) sort(v.begin(), v.end());
        sort(cuboids.begin(), cuboids.end(), [](auto & a, auto & b) {
            if (a[0] == b[0] && a[1] == b[1]) return a[2] < b[2];
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int dp[n];
        dp[0] = cuboids[0][2];
        for(int i = 1; i < n; i++) {
            int tmp = 0;
            for(int j = 0; j < i; j++) {
                if (cuboids[j][0]<= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = tmp + cuboids[i][2];
        }
        int res = 0;
        for(int i = 0; i < n; i++) res = max(res, dp[i]);
        return res;
    }
};
