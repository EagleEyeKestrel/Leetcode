//
//  main.cpp
//  dp题，关键是怎么更新dp[i][j]（代表着前i个字符删除j个
//  讨论标准是最后一个字符删不删。如果删除最后一个字符，那么就是dp[i-1][j-1]
//  关键是如果不删除。那么就从后往前遍历，争取尽可能保留多个和s[i-1]相同的字符，其他的删掉
//  直到删除的字符数已经超过j。这个严谨的证明比较难，但是合乎直觉
//  复杂度O(n3)，符合数据规模
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int cnt) {
        if (cnt == 1) return 1;
        if (cnt >= 2 && cnt <= 9) return 2;
        if (cnt < 100) return 3;
        return 4;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k && j <= i; j++) {
                if (j > 0) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = i;
                int same = 0, diff = 0, now = i;
                while (now >= 1 && diff <= j) {
                    if (s[now - 1] == s[i - 1]) {
                        same++;
                        dp[i][j] = min(dp[i][j], dp[now - 1][j - diff] + f(same));
                    } else {
                        diff++;
                        if (diff > j) break;
                        dp[i][j] = min(dp[i][j], dp[now - 1][j - diff] + f(same));
                    }
                    now--;
                }
            }
        }
        return dp[n][k];
    }
};
