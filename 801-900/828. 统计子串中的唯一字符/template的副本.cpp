//
//  main.cpp
//  记录下每个字母出现的索引序列
//  一个字符被统计进去说明只能出现一次。对于位置v[i][j]，可以出现d1*d2次，累加即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), mod = 1e9 + 7, res =0;
        vector<int> v[26];
        for (int i = 0; i < n; i++) {
            v[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            long long tmp = 0;
            v[i].push_back(n);
            v[i].insert(v[i].begin(), -1);
            for (int j = 1; j < v[i].size() - 1; j++) {
                int d1 = v[i][j] - v[i][j - 1], d2 = v[i][j + 1] - v[i][j];
                tmp = (tmp + (long long)d1 * d2) % mod;
            }
            res = (res + tmp) % mod;
        }
        return res;
    }
};
