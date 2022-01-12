//
//  main.cpp
//  当时感觉不知道如何处理，然后就写了个拓扑排序。
//  写得比较麻烦，先把所有字符串变成对应的int，建立双向索引id和name
//  success存储需要的菜
//  然后建图g，拓扑排序
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<int> success;
        map<string, int> id;
        vector<string> res;
        string name[1200];
        int now = 1;
        for (auto &s: recipes) {
            if (!id.count(s)) {
                name[now] = s;
                id[s] = now++;
            }
        }
        for (auto &v: ingredients) {
            for (auto &s: v) {
                if (!id.count(s)) {
                    name[now] = s;
                    id[s] = now++;
                }
            }
        }
        for (auto &s: recipes) success.insert(id[s]);
        int g[1200][1200];
        memset(g, 0, sizeof(g));
        int in[1200];
        memset(in, 0, sizeof(in));
        for (int i = 0; i < recipes.size(); i++) {
            int to = id[recipes[i]];
            for (int j = 0; j < ingredients[i].size(); j++) {
                g[id[ingredients[i][j]]][to] = 1;
                in[to]++;
            }
        }
        queue<int> q;
        for (auto &s: supplies) {
            if (id.count(s)) q.push(id[s]);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 1200; i++) {
                if (g[u][i]) {
                    in[i]--;
                    if (in[i] == 0) {
                        q.push(i);
                        if (success.count(i)) res.push_back(name[i]);
                    }
                }
            }
        }
        return res;
    }
};
