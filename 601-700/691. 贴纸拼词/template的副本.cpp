//
//  main.cpp
//  状压，穷举最后target用了哪一个单词
//  但是不知道为什么这个算法效率这么低。。要几百ms
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), m = 1 << n, l = stickers.size();
        long dp[m];
        dp[0] = 0;
        int cnt[l][26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < l; i++) {
            for (char c: stickers[i]) cnt[i][c - 'a']++;
        }
        for (int state = 1; state < m; state++) {
            dp[state] = INT_MAX;
            for (int i = 0; i < l; i++) {
                int tmp[26];
                memset(tmp, 0, sizeof(tmp));
                int mask = state;
                for (int k = 0; k < n; k++) {
                    if (state >> k & 1) {
                        if (tmp[target[k] - 'a'] < cnt[i][target[k] - 'a']) {
                            tmp[target[k] - 'a']++;
                            mask ^= (1 << k);
                        }
                    }
                }
                dp[state] = min(dp[state], dp[mask] + 1);
            }
        }
        return dp[m - 1] == INT_MAX ? -1 : dp[m - 1];
    }
};
