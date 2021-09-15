//
//  main.cpp
//  比较难。。数位dp + kmp
//  学习了一下数位dp，很不错，关键在于这个状态的定义很巧妙。
//  对于本题来讲，多了字符串的限制，不能有evil子串。所以对一个状态需要记录当前匹配成功evil的长度
//  失效的时候用p数组转移
//  注意，对两个不同的字符串要清空一下dp数组。否则会出问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[510][51][2];//pos, match, limit
    int p[60];
    string evil;
    void getp() {
        int n = evil.size();
        p[0] = 0, p[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i];
            while (j && evil[j] != evil[i]) j = p[j];
            p[i + 1] = (evil[i] == evil[j] ? j + 1 : 0);
        }
    }
    int next(char c, int match) {
        int j = match;
        while (j && c != evil[j]) j = p[j];
        if (c == evil[j]) j++;
        return j;
    }
    int f(string &s, int pos, int match, int limit) {
        if (s.size() == pos) return 1;
        if (dp[pos][match][limit] != -1) return dp[pos][match][limit];
        char up = (limit ? s[pos] : 'z');
        int res = 0;
        for (char c = 'a'; c <= up; c++) {
            if (match == evil.size() - 1 && c == evil.back()){
                continue;
            }
            int newmatch, newlimit = (limit && c == up);
            if (c == evil[match]) newmatch = match + 1;
            else newmatch = next(c, match);
            res = (res + f(s, pos + 1, newmatch, newlimit)) % mod;
        }
        dp[pos][match][limit] = res;
        return res;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->evil = evil;
        getp();
        memset(dp, -1, sizeof(dp));
        int res1 = f(s1, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        int res2 = f(s2, 0, 0, 1);
        int res = (res2 - res1 + mod) % mod;
        if (s1.find(evil) == string::npos) res++;
        return res;
    }
};
