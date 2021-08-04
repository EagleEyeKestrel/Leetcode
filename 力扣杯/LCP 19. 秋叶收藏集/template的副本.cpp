//
//  main.cpp
//  dp。由于最终结果一定会分成三段，那么用三个数字表示三种状态即可。一遍遍历
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        int dp[n][3];
        dp[0][0] = (leaves[0] == 'y');
        dp[0][1] = 1e6;
        dp[0][2] = 1e6;
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + (leaves[i] == 'y');
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (leaves[i] == 'r');
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (leaves[i] == 'y');
        }
        return dp[n - 1][2];
    }
};
