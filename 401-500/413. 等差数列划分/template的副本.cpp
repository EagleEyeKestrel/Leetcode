//
//  main.cpp
//  一开始看成了子序列，后来发现其实是子数组，就简单多了
//  对A[i]结尾的等差子数组，A[i-2],A[i-1],A[i]算一个，其余的都是以A[i-1]结尾的加上A[i]
//  显然空间可以优化到O(1)的，懒就没写了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), res = 0;
        if (!n) return 0;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                res += dp[i];
            }
        }
        return res;
    }
};
