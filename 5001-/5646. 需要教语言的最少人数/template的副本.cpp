//
//  main.cpp
//  阅读理解。。
//  s[i]表示第i个人掌握的所有语言
//  f[i]表示第i个关系，在没有教新语言的情况下是否互通
//  然后遍历第i种语言，定义一个新的集合newlearner因为可能有人新学会语言
//  然后遍历每个关系，对每个不会这个语言的教语言，统计个数，取最小值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(), k = friendships.size();
        unordered_set<int> s[m + 1];
        for (int i = 0; i < m; i++) {
            for (int language: languages[i]) {
                s[i + 1].insert(language);
            }
        }
        int f[k];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < k; i++) {
            int a = friendships[i][0], b = friendships[i][1];
            for (int x: s[a]) {
                if (s[b].count(x)) {
                    f[i] = 1;
                    break;
                }
            }
        }
        int res = m;
        for (int i = 1; i <= n; i++) {
            unordered_set<int> newlearner;
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                if (f[j]) continue;
                int a = friendships[j][0], b = friendships[j][1];
                if (!s[a].count(i) && !newlearner.count(a)) {
                    newlearner.insert(a);
                    cnt++;
                }
                if (!s[b].count(i) && !newlearner.count(b)) {
                    newlearner.insert(b);
                    cnt++;
                }
            }
            res = min(res, cnt);
        }
        return res;
    }
};
