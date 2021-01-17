//
//  main.cpp
//  这里可能直接以string建并查集更好
//  用邮箱直接判断，每次直接合并邮箱
//  f是邮箱的父亲
//  owner是一个邮箱的主人名字
//  mp存储一个邮箱祖先对应的所有邮箱集合
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<string, string> f;
    unordered_map<string, string> owner;
    unordered_map<string, set<string>> mp;
    string findp(string s) {
        return f[s] == s ? s : (f[s] = findp(f[s]));
    }
    void merge(string a, string b) {
        string pa = findp(a), pb = findp(b);
        f[pa] = pb;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> res;
        for (auto &account: accounts) {
            for (int i = 1; i < account.size(); i++) {
                f[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        for (auto &account: accounts) {
            for (int i = 2; i < account.size(); i++) {
                merge(account[1], account[i]);
            }
        }
        for (auto &account: accounts) {
            for (int i = 1; i < account.size(); i++) {
                mp[findp(account[i])].insert(account[i]);
            }
        }
        for (auto it: mp) {
            string name = owner[it.first];
            vector<string> mails(it.second.begin(), it.second.end());
            mails.insert(mails.begin(), name);
            res.push_back(mails);
        }
        return res;
    }
};
