//
//  main.cpp
//  用dp[n]表示有n个元素的二叉搜索树的种类个数，穷举左儿子有j in 0 to i-1个元素
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
