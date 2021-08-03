//
//  main.cpp
//  和1931题一模一样。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    string f(int x) {
        string res(3, '0');
        int i = 0;
        while (x) {
            res[i] = x % 3 + '0';
            i++;
            x /= 3;
        }
        return res;
    }
    int numOfWays(int n) {
        int maxv = 27;
        vector<int> g[maxv];
        for (int i = 0; i < maxv; i++) {
            for (int j = 0; j < maxv; j++) {
                string s1 = f(i), s2 = f(j);
                int flag = 1;
                for (int k = 0; k < 2; k++) {
                    if (s1[k] == s1[k + 1] || s2[k] == s2[k + 1]) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < 3; k++) {
                    if (s1[k] == s2[k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) g[j].push_back(i);
            }
        }
        int dp[maxv];
        for (int i = 0; i < 27; i++) {
            if (!g[i].empty()) dp[i] = 1;
            else dp[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int tmp[maxv];
            memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j < 27; j++) {
                for (int x: g[j]) {
                    tmp[j] = (tmp[j] + dp[x]) % mod;
                }
            }
            memcpy(dp, tmp, sizeof(dp));
        }
        int res = 0;
        for (int i = 0; i < 27; i++) res = (res + dp[i]) % mod;
        return res;
    }
};
