//
//  main.cpp
//  我的解法，先预处理每个人的收藏集合
//  然后对于第i个人，检查他的所有网页，vis[j]表示第j个人是不是收藏了这个网页
//  对于所有网页看过去后，看哪个人vis[j]仍然等于1，说明是这个人的子集
//  复杂度O(100*500*100)但是常数较大
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        unordered_set<string> s[n];
        for (int i = 0; i < n; i++) {
            for (string& str: favoriteCompanies[i]) {
                s[i].insert(str);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int vis[n];
            int flag = 1;
            for (int j = 0; j < n; j++) vis[j] = 1;
            for (string& str: favoriteCompanies[i]) {
                for (int j = 0; j < n; j++) {
                    if (favoriteCompanies[j].size() < favoriteCompanies[i].size() || j == i) {
                        vis[j] = 0;
                        continue;
                    }
                    if (!s[j].count(str)) vis[j] = 0;
                }
            }
            for (int j = 0; j < n; j++) {
                if (vis[j] == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};
