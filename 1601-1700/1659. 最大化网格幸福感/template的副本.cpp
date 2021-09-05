//
//  main.cpp
//  第一次学习，轮廓线dp
//  dp[pos][mask][i][j]表示位置是pos，前n个位置的状态是mask，以及两种人各剩下i，j个
//  cal计算 一个mask 新加入一个状态t 再取消掉过期的状态 变成什么状态
//  getbit看pos之前第bit个位置是多少
//  然后就用记忆化搜索就行。普通状压应该也可以吧，感觉可能会慢一些
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int dp[25][243][7][7];
    int three[5] = {1, 3, 9, 27, 81};
    int score[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    int m, n;
    int cal(int mask, int t) {
        mask = mask % three[n - 1];
        mask = mask * 3 + t;
        return mask;
    }
    int getbit(int mask, int bit) {
        int remain = mask % (3 * three[bit]);
        return remain / three[bit];
    }
    int f(int pos, int mask, int cnti, int cnte) {
        if (pos >= m * n) return 0;
        if (dp[pos][mask][cnti][cnte] != -1) return dp[pos][mask][cnti][cnte];
        if (cnti == 0 && cnte == 0) return 0;
        int res = 0;
        for (int t = 0; t < 3; t++) {
            if (t == 0) {
                int newmask = cal(mask, t);
                res = max(res, f(pos + 1, newmask, cnti, cnte));
                continue;
            }
            int newmask = cal(mask, t), newcnti = cnti, newcnte = cnte;
            if (cnti == 0 && t == 1 || cnte == 0 && t == 2) continue;
            if (t == 1) newcnti--;
            if (t == 2) newcnte--;
            int tmp = f(pos + 1, newmask, newcnti, newcnte);
            if (t == 1) tmp += 120;
            if (t == 2) tmp += 40;
            int row = pos / n, col = pos % n;
            if (row > 0) {
                int bit = getbit(mask, n - 1);
                tmp += score[t][bit];
            }
            if (col > 0) {
                int bit = getbit(mask, 0);
                tmp += score[t][bit];
            }
            res = max(res, tmp);
        }
        dp[pos][mask][cnti][cnte] = res;
        return res;
    }
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, introvertsCount, extrovertsCount);
    }
};
