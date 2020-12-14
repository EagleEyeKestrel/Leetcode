//
//  main.cpp
//  题目不难，学习一下如何在lambda函数中用到外部数组
//  不知道为什么在函数内开cnt然后传cnt会得不到值？对这方面还不是很了解
//  这里发现可以借助传this指针来实现
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int cnt[26][26];
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), l = votes[0].size();
        memset(cnt, 0, sizeof(l));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                cnt[votes[i][j] - 'A'][j]++;
            }
        }
        string res = votes[0];
        sort(res.begin(), res.end(), [this, l](char a, char b) {
            for (int i = 0; i < l; i++) {
                int va = this->cnt[a - 'A'][i], vb = this->cnt[b - 'A'][i];
                if (va != vb) return va > vb;
            }
            return a < b;
        });
        return res;
    }
};
