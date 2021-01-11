//
//  main.cpp
//  也不难，要注意题目里说的是可以“重新排列”
//  所以针对每个s[l:r]，看有多少个字母只出现奇数次就可以了
//  如果子串长度是偶数，需要oddcnt/2次替换
//  如果子串长度是奇数，中间位置可以放一个，所以还是oddcnt/2次
//  至于怎么求s[l:r]，每次遍历求肯定超时，直接预处理前缀和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int cnt[26][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (!i) cnt[j][i] = (s[i] - 'a' == j);
                else {
                    if (s[i] - 'a' == j) cnt[j][i] = cnt[j][i - 1] + 1;
                    else cnt[j][i] = cnt[j][i - 1];
                }
            }
        }
        vector<bool> res;
        for (auto &q: queries) {
            int l = q[0], r = q[1], k = q[2];
            int tmp[26];
            int oddcnt = 0;
            for (int j = 0; j < 26; j++) {
                if (!l) tmp[j] = cnt[j][r];
                else tmp[j] = cnt[j][r] - cnt[j][l - 1];
                if (tmp[j] % 2) oddcnt++;
            }
            res.push_back(k >= oddcnt / 2);
        }
        return res;
    }
};
