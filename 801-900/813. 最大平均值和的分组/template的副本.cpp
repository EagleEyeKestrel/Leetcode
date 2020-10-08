//
//  main.cpp
//  O(n^3)的经典dp，用dp[i][k]表示前i个数分成k组的最大分数
//  预处理前缀和。然后计算dp[i][k]时，穷举最后一个区间的左端点j，计算新的分数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        double s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + A[i - 1];
        double dp[n + 1][K + 1];
        for(int i = 1; i <= n; i++) dp[i][1] = s[i] / i;
        for(int k = 2; k <= K; k++) {
            for(int i = k; i <= n; i++) {
                double tmp = 0;
                for(int j = k; j <= i; j++) {
                    tmp = max(tmp, dp[j - 1][k - 1] + (s[i] - s[j - 1]) / (i - j + 1));
                }
                dp[i][k] = tmp;
            }
        }
        return dp[n][K];
    }
};
