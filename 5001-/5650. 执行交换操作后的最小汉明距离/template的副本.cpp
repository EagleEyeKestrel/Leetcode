//
//  main.cpp
//  先用并查集合并能够任意交换的索引集
//  对于一个索引集，检查source target对应的所有元素，存在cnt1和cnt2里
//  一个索引集里，最优情况使得cnt1和cnt2里有最多的元素对相等。
//  这个索引集的汉明距离就是索引集的大小减去相等的元素对数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010], sz[100010];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int x, int y) {
        int px = findp(x), py = findp(y);
        if (sz[px] <= sz[py]) {
            p[px] = py;
        } else {
            p[py] = px;
        }
        if (sz[px] == sz[py] && px != py) sz[py]++;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), res = 0;
        for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
        for (auto &v: allowedSwaps) {
            merge(v[0], v[1]);
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int pi = findp(i);
            mp[pi].push_back(i);
        }
        for (auto it: mp) {
            unordered_set<int> s;
            int cnt = 0;
            unordered_map<int, int> cnt1, cnt2;
            for (int index: it.second) {
                cnt1[source[index]]++;
                cnt2[target[index]]++;
                s.insert(source[index]);
            }
            for (int val: s) {
                cnt += min(cnt1[val], cnt2[val]);
            }
            res += it.second.size() - cnt;
        }
        return res;
    }
};
