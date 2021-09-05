//
//  main.cpp
//  题目说的乱七八糟的。其实就是说，每次从words中某个单词，索引为k的地方 取一个字母，来构造target
//  然后用完k之后就不能在用k以及小于k的索引了
//  所以就有点类似于背包问题。dp[i][j]表示索引为0-i 凑出target 0-j的部分的方案数
//  dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*cnt,其中cnt是说有多少个word[i]==target[j]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int m = target.size(), n = words.size(), l = words[0].size();
        int dp[l][m], cnt[l][26];
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for (auto &word: words) {
            for (int i = 0; i < l; i++) {
                cnt[i][word[i] - 'a']++;
            }
        }
        dp[0][0] = cnt[0][target[0] - 'a'];
        for (int i = 1; i < l; i++) {
            for (int j = 0; j <= min(i, m - 1); j++) {
                if (j > 0)  dp[i][j] = (dp[i - 1][j] + (long long)dp[i - 1][j - 1] * cnt[i][target[j] - 'a'] % mod) % mod;
                else dp[i][j] = (dp[i - 1][j] + cnt[i][target[j] - 'a']) % mod;
            }
        }
        return dp[l - 1][m - 1];
    }
};
