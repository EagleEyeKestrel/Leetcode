//
//  main.cpp
//  O(n3)的算法是比较简单的
//  O(n2)的算法比较难想。可以参考题解学习一下，这里是代码实现
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sum(int s[], int l, int r) {
        if (l > r) return 0;
        return l ? s[r] - s[l - 1] : s[r];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int g[n][n], s[n], dp[n][n], ml[n][n], mr[n][n];
        memset(ml, 0, sizeof(ml));
        memset(mr, 0, sizeof(mr));
        s[0] = stoneValue[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + stoneValue[i];
        for (int i = 0; i < n; i++) {
            g[i][i] = i - 1;
            int r = i - 1;
            for (int j = i + 1; j < n; j++) {
                while (r + 1 < j && sum(s, i, r + 1) <= sum(s, r + 2, j)) r++;
                g[i][j] = r;
            }
        }
        for (int l = n - 1; l >= 0; l--) {
            dp[l][l] = 0;
            ml[l][l] = stoneValue[l];
            mr[l][l] = stoneValue[l];
            for (int r = l + 1; r < n; r++) {
                int mid = g[l][r];
                dp[l][r] = 0;
                if (sum(s, l, mid) == sum(s, mid + 1, r)) {
                    dp[l][r] = max(ml[l][mid], mr[mid + 1][r]);
                } else {
                    if (mid >= l) dp[l][r] = max(dp[l][r], ml[l][mid]);
                    if (mid + 2 <= r) dp[l][r] = max(dp[l][r], mr[mid + 2][r]);
                }
                ml[l][r] = max(dp[l][r] + sum(s, l, r), ml[l][r - 1]);
                mr[l][r] = max(dp[l][r] + sum(s, l, r), mr[l + 1][r]);
            }
        }
        return dp[0][n - 1];
    }
};
