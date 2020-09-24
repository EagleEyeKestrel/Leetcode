//
//  main.cpp
//  用dp的话确实很简单。。好像还有个很厉害的算法
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), res = 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
