//
//  main.cpp
//  刚学的数位dp，又用到了
//  pos：当前第几位 mask：使用过哪些数字了 flag：是否处于前导0 limit：是否是紧的
//  至少有1个重复，转化成n-一位都不重复
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string s;
    int dp[10][1024][2][2];
    int f(int pos, int mask, int flag, int limit) {
        if (pos == s.size()) return flag == 0;
        if (dp[pos][mask][flag][limit] != -1) return dp[pos][mask][flag][limit];
        int up = limit ? s[pos] - '0' : 9, res = 0;
        for (int i = 0; i <= up; i++) {
            if (i == 0) {
                if (flag) {
                    res += f(pos + 1, mask, flag, limit && i == up);
                } else {
                    if (mask & 1) continue;
                    else res += f(pos + 1, mask | 1, flag, limit && i == up);
                }
            } else {
                if (mask >> i & 1) continue;
                res += f(pos + 1, mask | (1 << i), 0, limit && i == up);
            }
        }
        dp[pos][mask][flag][limit] = res;
        return res;
    }
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return n - f(0, 0, 1, 1);
    }
};
