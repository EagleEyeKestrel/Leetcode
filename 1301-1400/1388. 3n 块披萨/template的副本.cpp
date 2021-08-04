//
//  main.cpp
//  问题的关键在于，这种取披萨方式等价于从n个环状披萨中不相邻地取n/3块，变成了打家劫舍问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(vector<int>& v) {
        int n = v.size();
        int dp[n][n / 3 + 2];
        memset(dp, 0, sizeof(dp));
        //dp[i][j] = max(dp[i-1][j], v[i] + dp[i - 2][j - 1])
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= min(i + 1, n / 3 + 1); j++) {
                dp[i][j] = i ? dp[i - 1][j] : 0;
                dp[i][j] = max(dp[i][j], v[i] + (i >= 2 ? dp[i - 2][j - 1] : 0));
            }
        }
        return dp[n - 1][n / 3 + 1];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> v1(slices.begin(), slices.begin() + n - 1);
        vector<int> v2(slices.begin() + 1, slices.end());
        return max(f(v1), f(v2));
    }
};
