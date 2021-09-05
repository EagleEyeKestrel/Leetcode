//
//  main.cpp
//  状压dp，用dp[mask]表示一个子集弄下来最少需要多少时间
//  加入新的工作i，根据余数判断是直接加 还是需要加上sessiontime
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int dp[1 << n];
        for (int i = 0; i < 1 << n; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int mask = 0; mask < 1 << n; mask++) {
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                int news = mask | (1 << i);
                int newt = (dp[mask] % sessionTime + tasks[i] <= sessionTime ? dp[mask] + tasks[i] : dp[mask] - dp[mask] % sessionTime + sessionTime + tasks[i]);
                dp[news] = min(dp[news], newt);
            }
        }
        int res = dp[(1 << n) - 1];
        return res % sessionTime ? res / sessionTime + 1 : res / sessionTime;
    }
};
