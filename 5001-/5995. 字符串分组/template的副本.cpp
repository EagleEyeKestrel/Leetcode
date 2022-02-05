//
//  main.cpp
//  比较无聊的并查集，注意一个坑点是字符串可能相同
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[20010];
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        p[px] = py;
    }
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) p[i] = i;
        int hash[n];
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char c: words[i]) mask |= (1 << (c - 'a'));
            hash[i] = mask;
            mp[mask].push_back(i);
        }
        for (auto &it: mp) {
            auto &v = it.second;
            for (int i = 0; i < v.size() - 1; i++) {
                merge(v[i], v[i + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            int mask = hash[i];
            for (int j = 0; j < 26; j++) {
                int newmask = mask ^ (1 << j);
                if (mp.count(newmask)) merge(i, mp[newmask][0]);
            }
            for (int j = 0; j < 26; j++) {
                if (mask >> j & 1) {
                    for (int k = 0; k < 26; k++) {
                        if (k == j) continue;
                        if ((mask >> k & 1) == 0) {
                            int newmask = mask ^ (1 << j) ^ (1 << k);
                            if (mp.count(newmask)) merge(i, mp[newmask][0]);
                        }
                    }
                }
            }
        }
        int sz[n];
        memset(sz, 0, sizeof(sz));
        set<int> se;
        for (int i = 0; i < n; i++) sz[find(i)]++, se.insert(find(i));
        return {(int)se.size(), *max_element(sz, sz + n)};
    }
};