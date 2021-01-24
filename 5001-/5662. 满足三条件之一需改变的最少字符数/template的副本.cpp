//
//  main.cpp
//  三种情况各自算一下就行了
//  前两种的话，可以穷举分界线，让a中的字符都小于等于某个值，b中的都大于，取最小值
//  一开始res初始化成了m，没想到因为这个WA了一次，比如"a"和"abcda"，就不止一次啊
//  cnt那边可以前缀和数组优化一下，不过不优化照样过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& a, string& b) {
        int m = a.size(), n = b.size(), res = m + n;
        int cnt1[26], cnt2[26];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (char c: a) cnt1[c - 'a']++;
        for (char c: b) cnt2[c - 'a']++;
        for (char c = 'a'; c < 'z'; c++) {
            int tmp = 0;
            for (int i = c - 'a' + 1; i < 26; i++) {
                tmp += cnt1[i];
            }
            for (int i = 0; i <= c - 'a'; i++) {
                tmp += cnt2[i];
            }
            res = min(res, tmp);
        }
        return res;
    }
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        int res = min(f(a, b), f(b, a));
        int cnt1[26], cnt2[26];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (char c: a) cnt1[c - 'a']++;
        for (char c: b) cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            res = min(res, m - cnt1[i] + n - cnt2[i]);
        }
        return res;
    }
};
