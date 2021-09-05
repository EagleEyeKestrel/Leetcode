//
//  main.cpp
//  用dp[i][j]表示区间[i,j] 尽可能的合成之后，所需要的最小代价
//  然后穷举区间p，表示最后一次合并发生在堆[i,p] [p+1,j]
//  要注意，如果两个的余数加起来大于k，说明这次合并是无效的，直接跳过。
//  如果等于k，说明两个区间各自合并之后还可以继续合并
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (n <= 1) return 0;
        if (k > 2 && n % (k - 1) != 1) return -1;
        int dp[n][n], sum[n];
        sum[0] = stones[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + stones[i];
        memset(dp, 0, sizeof(dp));
        for (int l = k; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int p = i; p < j; p++) {
                    int l1 = p - i + 1, l2 = j - p;
                    int rest1 = l1 % (k - 1) ? l1 % (k - 1) : k - 1;
                    int rest2 = l2 % (k - 1) ? l2 % (k - 1) : k - 1;
                    if (rest1 + rest2 > k) continue;
                    int tmp = dp[i][p] + dp[p + 1][j];
                    if (rest1 + rest2 == k) tmp += (i ? sum[j] - sum[i - 1] : sum[j]);
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }
        return dp[0][n - 1];
    }
};
