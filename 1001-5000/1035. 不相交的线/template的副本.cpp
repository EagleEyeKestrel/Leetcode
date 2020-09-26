//
//  main.cpp
//  等价于最长公共子序列？
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
