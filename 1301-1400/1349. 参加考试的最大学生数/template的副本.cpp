//
//  main.cpp
//  数据范围很小，考虑状态压缩dp
//  很显然每一行能坐多少人，只取决于上一行的状态。用dp[i][j]表示0-i行 第i-1行坐mask状态的人，最多能坐几个人
//  直接遍历上一行所有状态即可，复杂度大概是m4^n
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(vector<char> &v) {
        int res = 0;
        for (char c: v) {
            res <<= 1;
            if (c == '.') res++;
        }
        return res;
    }
    int check(int state) {
        return (state & (state << 1)) == 0;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size(), res = 0;
        int dp[m][1 << n];
        memset(dp, 0, sizeof(dp));
        int row0 = f(seats[0]);
        for (int mask = row0; mask; mask = (mask - 1) & row0) {
            if (check(mask)) dp[0][mask] = __builtin_popcount(mask);
            else dp[0][mask] = -1;
        }
        for (int i = 1; i < m; i++) {
            int rowi = f(seats[i]);
            for (int mask = rowi; ; mask = (mask - 1) & rowi) {
                dp[i][mask] = -1;
                if (!check(mask)) {
                    continue;
                }
                unordered_set<int> s;
                for (int k = 0; k < n; k++) {
                    if (mask >> k & 1) s.insert(k);
                }
                for (int lastState = 0; lastState < (1 << n); lastState++) {
                    if (dp[i - 1][lastState] == -1) continue;
                    int flag = 1;
                    for (int k = 0; k < n; k++) {
                        if ((lastState >> k & 1) && (s.count(k - 1) || s.count(k + 1))) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {
                        dp[i][mask] = max(dp[i][mask], __builtin_popcount(mask) + dp[i - 1][lastState]);
                    }
                }
                if (!mask) break;
            }
        }

        for (int j = 0; j < (1 << n); j++) res = max(res, dp[m - 1][j]);
        return res;
    }
};
