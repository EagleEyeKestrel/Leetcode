//
//  main.cpp
//  数据范围很小，我是走的回溯
//  先预处理所有的组合数，应该都不会超过double。然后dfs(i,balls,s)里
//  i表示当前处理到第i种球，s是已经选了多少个球。选到n/2个球之后就停止
//  查看种类数是否相等，如果相等的话，就按组合数计算有多少种拿法。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    double son = 0;
    int s1[10];
    double c[49][49];
    int k, n;
    void dfs(int i, vector<int>& balls, int s) {
        if (s == n / 2) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < k; j++) {
                if (s1[j]) cnt1++;
                if (balls[j] - s1[j] > 0) cnt2++;
            }
            if (cnt1 != cnt2) return;
            double tmp = 1;
            for (int j = 0; j < k; j++) {
                if (s1[j]) {
                    tmp *= c[balls[j]][s1[j]];
                }
            }
            son += tmp;
            return;
        }
        if (i == k || s > n / 2) return;
        for (int j = 0; j <= balls[i] && j + s <= n / 2; j++) {
            int old = s1[i];
            s1[i] = j;
            dfs(i + 1, balls, s + j);
            s1[i] = old;
        }
    }
    double getProbability(vector<int>& balls) {
        k = balls.size(), n = 0;
        double mother = 1;
        for (int x: balls) n += x;
        memset(s1, 0, sizeof(s1));
        for (int i = 1; i <= 48; i++) c[i][0] = 1, c[i][i] = 1;
        for (int i = 2; i <= 48; i++) {
            for (int j = 1; j < i; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        dfs(0, balls, 0);
        return son / c[n][n / 2];
    }
};
