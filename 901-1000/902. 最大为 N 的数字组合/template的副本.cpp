//
//  main.cpp
//  比较简单的数位dp，用flag表示是否处于前导0状态
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[10];
    string s;
    int dp[10][2][2];
    int f(int pos, int flag, int limit) {
        if (pos == s.size()) return flag == 0;
        if (dp[pos][flag][limit] != -1) return dp[pos][flag][limit];
        int up = limit ? s[pos] - '0' : 9, res = 0;
        if (flag) {
            res += f(pos + 1, 1, 0);
        }
        for (int i = 1; i <= up; i++) {
            if (!vis[i]) continue;
            res += f(pos + 1, 0, limit && i == up);
        }
        dp[pos][flag][limit] = res;
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(vis, 0, sizeof(vis));
        for (string digit: digits) vis[digit[0] - '0'] = 1;
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 1);
    }
};
