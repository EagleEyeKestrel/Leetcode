//
//  main.cpp
//  很久没有ak周赛啦，这道题做出来了
//  开始想着不同query之间是否存在着某种联系，像离线做法那样，但发现难以找到
//  想去用一个滚动数组dp[k]表示长度为n时候乘积为k的方案数，但发现光是更新就超时了
//  所以尝试在常数/ log 时间内算出来
//  其实可以发现一个数可以质因数分解成p1^q1 * p2 ^ q2 * ...
//  说明有q1个p1，要生成长度为n的数组，即把q1个数放进n个位置
//  等同于组合数学中，x1+x2+...+xn = q的非负整数解的个数，我们知道是C(n+q-1, q)
//  所以预处理组合数，预处理每个数的最小质因数，然后就可以做了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int minFactor[10050], c[10050][50];
    void pre() {
        memset(minFactor, 0, sizeof(minFactor));
        for (int i = 2; i < 10050; i++) {
            if (minFactor[i] == 0) {
                minFactor[i] = i;
                for (int j = 2 * i; j < 10050; j += i) {
                    if (minFactor[j] == 0) {
                        minFactor[j] = i;
                    }
                }
            }
        }
        c[1][0] = 1;c[1][1] = 1;
        for (int i = 2; i < 10050; i++) {
            c[i][0] = 1;
            for (int j = 1; j < 50; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
        
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        pre();
        for (auto &query: queries) {
            int n = query[0], k = query[1];
            if (k == 1) {
                ans.push_back(1);
                continue;
            }
            vector<int> exps;
            while (k > 1) {
                int factor = minFactor[k], cnt = 0;
                while (k % factor == 0) {
                    k /= factor;
                    cnt++;
                }
                exps.push_back(cnt);
            }
            long long res = 1;
            for (int i = 0; i < exps.size(); i++) {
                res = res * (c[n + exps[i] - 1][exps[i]]) % mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
