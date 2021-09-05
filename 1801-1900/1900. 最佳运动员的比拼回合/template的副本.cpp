//
//  main.cpp
//  第四题这次做了出来
//  状态压缩，搜索。用state表示剩余哪些人，从0开始标号
//  如果a和b两个人都已经不在了，就退出
//  如果都在，那么继续往下递归，穷举每一轮分别都是谁赢，然后得到新的state，继续下一轮递归
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int resmin = INT_MAX, resmax = 0;
    int a, b;
    void dfs(int state, int rounds) {
        int n = __builtin_popcount(state);
        if (n < 2) return;
        
        if (((state >> a) & 1) == 0 || ((state >> b) & 1) == 0) return;
        
        int t = n >> 1, now = 0;
        int q[29];
        for (int i = 0; i <= 28; i++) {
            if ((state >> i) & 1) {
                q[now++] = i;
            }
        }
        for (int mask = 0; mask < (1 << t); mask++) {
            int newstate = 0;
            for (int i = 0; i < t; i++) {
                if ((mask >> i) & 1) {
                    newstate |= (1 << q[i]);
                } else {
                    newstate |= (1 << q[n - 1 - i]);
                }
                if (q[i] == a && q[n - 1 - i] == b || q[i] == b && q[n - 1 - i] == a) {
                    resmin = min(resmin, rounds);
                    resmax = max(resmax, rounds);
                    return;
                }
            }
            if (n & 1) newstate |= (1 << q[t]);
            dfs(newstate, rounds + 1);
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int state = 0;
        for (int i = 0; i < n; i++) state |= (1 << i);
        a = firstPlayer - 1, b = secondPlayer - 1;
        dfs(state, 1);
        return { resmin, resmax };
    }
};
