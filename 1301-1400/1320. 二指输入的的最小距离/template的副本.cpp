//
//  main.cpp
//  很显然，用dp[i][j][k]表示第i个字符时，两只手分别在j和k的最小代价
//  但其实并不用遍历所有的i,j,k，因为j和k必然有一个在word[i]上
//  穷举是左手还是右手。然后再穷举上一次i-1的状态，同样也分两种，复杂度是26*26*n(但是不知道为什么这么慢)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    pair<int, int> f(int d) {
        return {d / 6, d % 6};
    }
    int c(pair<int,int> p1, pair<int, int> p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }
    int minimumDistance(string word) {
        int n = word.size(), res = INT_MAX;
        int dp[n][26][26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int k = 0; k < 26; k++) dp[0][word[0] - 'A'][k] = 0, dp[0][k][word[0] - 'A'] = 0;
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < 26; k++) {
                dp[i][word[i] - 'A'][k] = INT_MAX;
                dp[i][k][word[i] - 'A'] = INT_MAX;
                for (int kk = 0; kk < 26; kk++) {
                    auto p1 = f(word[i] - 'A'), p2 = f(k);
                    auto pp1 = f(word[i - 1] - 'A'), pp2 = f(kk);
                    dp[i][word[i] - 'A'][k] = min(dp[i][word[i] - 'A'][k], dp[i - 1][word[i - 1] - 'A'][kk] + c(p1, pp1) + c(p2, pp2));
                    dp[i][word[i] - 'A'][k] = min(dp[i][word[i] - 'A'][k], dp[i - 1][kk][word[i - 1] - 'A'] + c(p1, pp2) + c(p2, pp1));
                    dp[i][k][word[i] - 'A'] = min(dp[i][k][word[i] - 'A'], dp[i - 1][word[i - 1] - 'A'][kk] + c(p2, pp1) + c(p1, pp2));
                    dp[i][k][word[i] - 'A'] = min(dp[i][k][word[i] - 'A'], dp[i - 1][kk][word[i - 1] - 'A'] + c(p2, pp2) + c(p1, pp1));
                }
             }
        }
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (dp[n - 1][j][k] != -1) res = min(res, dp[n - 1][j][k]);
            }
        }
        return res;
    }
};
