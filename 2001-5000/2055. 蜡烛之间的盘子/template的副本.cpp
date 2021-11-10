//
//  main.cpp
//  用ll[i], rr[i]表示离s[i]左/右最近的蜡烛即可
//  在处理每个q的时候，比赛的时候我还在二分。。做烦了，直接rr[L]就可以找到第一个蜡烛的位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int sum[n];
        sum[0] = (s[0] == '*');
        for (int i = 1; i < n; i++) {
            if (s[i] == '*') sum[i] = sum[i - 1] + 1;
            else sum[i] = sum[i - 1];
        }
        int ll[n], rr[n];
        int now = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') now = i;
            ll[i] = now;
        }
        now = n + 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') now = i;
            rr[i] = now;
        }
        vector<int> res;
        for (auto &q: queries) {
            int L = q[0], R = q[1];
            int p1 = rr[L], p2 = ll[R];
            if (p1 > p2) {
                res.push_back(0);
                continue;
            }
            res.push_back(p1 >= 1 ? sum[p2] - sum[p1 - 1] : sum[p2]);
        }
        return res;
    }
};
