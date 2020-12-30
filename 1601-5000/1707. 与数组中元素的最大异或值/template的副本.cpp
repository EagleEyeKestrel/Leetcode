//
//  main.cpp
//  比较难，没想到
//  想到使用离线算法，按照mi进行排序，对所有小于等于mi的数进行计算
//  由于异或结果肯定优先考虑最高位，数据结构可以用trie树
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int val;
        node* childs[2];
        node(int v) {
            val = v;
            memset(childs, 0, sizeof(childs));
        }
    };
    node* root;
    void add(int num) {
        node* now = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!now->childs[bit]) {
                now->childs[bit] = new node(bit);
            }
            now = now->childs[bit];
        }
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), l = 0;
        vector<int> res(m);
        int id2query[m];
        for (int i = 0; i < m; i++) id2query[i] = i;
        sort(id2query, id2query + m, [&queries](auto &a, auto &b) {
            return queries[a][1] < queries[b][1];
        });
        sort(nums.begin(), nums.end());
        root = new node(0);
        for (int i = 0; i < m; i++) {
            int xi = queries[id2query[i]][0], mi = queries[id2query[i]][1];
            while (l < nums.size() && nums[l] <= mi) {
                add(nums[l]);
                l++;
            }
            if (l == 0) {
                res[id2query[i]] = -1;
                continue;
            }
            int resval = 0;
            node* now = root;
            for (int i = 30; i >= 0; i--) {
                int bit = (xi >> i) & 1;
                if (now->childs[1 - bit]) {
                    resval = (resval << 1) + 1;
                    now = now->childs[1 - bit];
                } else {
                    resval = resval << 1;
                    now = now->childs[bit];
                }
            }
            res[id2query[i]] = resval;
        }
        return res;
    }
};
