//
//  main.cpp
//  关键在于怎么在O(1)判断两个字符串是否相等？
//  用字符串哈希的方法，把字符串看成一个p进制数，然后求前缀和，做差可以O(1)时间求出
//  由于不能重复，所用一个set去重
//  第一次写字符串哈希。要注意，不要加text[i-1]-'a'，这样的话比如说
//  "aaaaaa"里，a和aa的哈希值都是0，所以这里采取加1
//  或者直接不减，用131进制也可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7, p = 31;
    long long sum[2048], pow[2048];
    int getVal(string &text, int l, int r) {
        return ((sum[r] - sum[l - 1] * pow[r - l + 1]) % mod + mod) % mod;
    }
    int distinctEchoSubstrings(string text) {
        int n = text.size(), res = 0;
        sum[0] = 0;
        pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            sum[i] = (((sum[i - 1] * p) + text[i - 1] - 'a' + 1) % mod + mod) % mod;
            pow[i] = (pow[i - 1] * p) % mod;
        }
        unordered_set<int> se;
        for (int sz = 2; sz <= n; sz += 2) {
            for (int i = 1; i + sz - 1 <= n; i++) {
                int v1 = getVal(text, i, i + sz / 2 - 1);
                int v2 = getVal(text, i + sz / 2, i + sz - 1);
                if (v1 == v2) se.insert(v1);
            }
        }
        return se.size();
    }
};
