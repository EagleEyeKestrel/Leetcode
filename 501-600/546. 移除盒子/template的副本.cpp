//
//  main.cpp
//  比较困难的dp
//  dp[i][j][k]表示i到j范围内，k表示i左边有k个和boxes[i]一样的数
//  尽量让i和j中间和boxes[i]相等的数和i合并
//  所以先消掉i+1到l-1，这样l左边就有k+1个数一样了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if(!n) return 0;
        int dp[n][n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int k = 0; k <= i; k++) dp[i][i][k] = (k + 1) * (k + 1);
        }
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                for(int k = 0; k <= i; k++) {
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for(int l = i + 1; l <= j; l++) {
                        if(boxes[l] == boxes[i]) {
                            res = max(res, dp[i + 1][l - 1][0] + dp[l][j][k + 1]);
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return dp[0][n - 1][0];
    }
};
