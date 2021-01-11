//
//  main.cpp
//  并查集的题目
//  预处理出可以任意交换的索引集合，mp中存储了这些索引集合
//  对每个索引集合，我们都可以贪心的交换到字典序，然后放回字符串的原位置
//  比如""dcab", [[0,3],[1,2]]，里面有两个集合
//  我们只能把"db"排序成"bd", "ca"排序成"ac"，放回原位变成"bacd"
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int x, int y) {
        int px = findp(x), py = findp(y);
        p[px] = py;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for (int i = 0; i < n; i++) p[i] = i;
        for (auto &v: pairs) {
            merge(v[0], v[1]);
        }
        string res;
        res.resize(n);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[findp(i)].push_back(i);
        }
        for (auto it: mp) {
            vector<int> ids = it.second;
            string tmp = "";
            for (int id: ids) tmp.push_back(s[id]);
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < ids.size(); i++) {
                res[ids[i]] = tmp[i];
            }
        }
        return res;
    }
};
