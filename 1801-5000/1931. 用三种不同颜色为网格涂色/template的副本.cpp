//
//  main.cpp
//  思路很显然，把列用状态压缩成三进制数
//  用dp[i][j]表示前i列，最后一列状态为j的种数
//  那么dp[i][j]= \sum dp[i-1][masks]，其中masks是不与j冲突的状态数
//  需要预处理一下每个j不冲突的所有状态masks
//  本来以为这样做会超时，因为复杂度感觉在(n*243*243)
//  但实际上 相邻数字不一样的状态数是很少的，只有几十个。所以可以轻松过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int m;
    string f(int x) {
        string res(m, '0');
        int i = 0;
        while (x) {
            res[i] = x % 3 + '0';
            i++;
            x /= 3;
        }
        return res;
    }
    int colorTheGrid(int m, int n) {
        this->m = m;
        int maxv = pow(3, m);
        vector<int> g[maxv];
        for (int i = 0; i < maxv; i++) {
            for (int j = 0; j < maxv; j++) {
                string s1 = f(i), s2 = f(j);
                int flag = 1;
                for (int k = 0; k < m - 1; k++) {
                    if (s1[k] == s1[k + 1] || s2[k] == s2[k + 1]) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < m; k++) {
                    if (s1[k] == s2[k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) g[j].push_back(i);
            }
        }
        int dp[maxv];
        for (int i = 0; i < pow(3, m); i++) {
            if (!g[i].empty()) dp[i] = 1;
            else dp[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int tmp[maxv];
            memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j < pow(3, m); j++) {
                for (int x: g[j]) {
                    tmp[j] = (tmp[j] + dp[x]) % mod;
                }
            }
            memcpy(dp, tmp, sizeof(dp));
        }
        int res = 0;
        for (int i = 0; i < pow(3, m); i++) res = (res + dp[i]) % mod;
        return res;
    }
};
