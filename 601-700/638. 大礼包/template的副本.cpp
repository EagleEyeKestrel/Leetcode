//
//  main.cpp
//  没有想到比较好的dp方法，状压感觉会超时
//  用dfs，v表示已经买了的东西的数量，遍历大礼包，如果还可以买，就继续递归
//  感觉数据比较弱，dfs 4ms就过了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int res = INT_MAX;
    int n, m;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, vector<int> &v, int now) {
        int tmp = now;
        for (int i = 0; i < n; i++) {
            if (v[i] < needs[i]) tmp += price[i] * (needs[i] - v[i]);
        }
        res = min(res, tmp);
        for (auto &s: special) {
            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (v[i] + s[i] > needs[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                for (int i = 0; i < n; i++) v[i] += s[i];
                dfs(price, special, needs, v, now + s.back());
                for (int i = 0; i < n; i++) v[i] -= s[i];
            }
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size(), m = special.size();
        vector<int> v(n, 0);
        dfs(price, special, needs, v, 0);
        return res;
    }
};
