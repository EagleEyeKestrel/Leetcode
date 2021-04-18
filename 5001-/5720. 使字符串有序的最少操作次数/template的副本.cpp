//
//  main.cpp
//  首先一个关键，这个啰哩啰嗦的操作，等价于获取上一个排列
//  然后就变成如何求字符串s的排列序数
//  比如leetcode，穷举每一位，第一位l,在l之前用字符序数可以是e,c，所以有4*7!种第一位不是l的字符串排位在前面
//  但要排除掉重复情况，所以还需要除以3!(注意这里要除的是所有字母的重复情况)
//  为了方便算排列组合，预处理所有的阶乘
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int qpow(int a, int b) {
        long long res = 1, tmp = a;
        while (b) {
            if (b & 1) res = (res * tmp) % mod;
            b >>= 1;
            tmp = (tmp * tmp) % mod;
        }
        return res % mod;
    }
    int fac[3010];
    void pre() {
        fac[0] = 1;
        fac[1] = 1;
        for (int i = 2; i < 3010; i++) {
            fac[i] = ((long long)fac[i - 1] * i) % mod;
        }
    }
    int makeStringSorted(string s) {
        pre();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s) cnt[c - 'a']++;
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            long long tmp = fac[s.size() - i - 1], count = 0;
            for (int j = 0; j < s[i] - 'a'; j++) {
                count += cnt[j];
            }
            tmp = (tmp * count) % mod;
            for (int j = 0; j < 26; j++) {
                if (cnt[j]) {
                    tmp = (tmp * qpow(fac[cnt[j]], mod - 2)) % mod;
                }
            }
            cnt[s[i] - 'a']--;
            res = (res + tmp) % mod;
        }
        return res;
    }
};
