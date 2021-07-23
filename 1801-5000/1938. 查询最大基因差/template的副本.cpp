//
//  main.cpp
//  在之前的基础上很自然会想到0-1字典树维护当前所有的数字
//  然后对于每一个查询，贪心查看当前字典树中最大的异或值
//  关键是应该按照什么顺序去处理queries？每个节点到根可能会经过不同的路径
//  这个技巧之前没有见过。每个节点到根的所有数，刚好是dfs的时候栈里的所有数字
//  所以一个思路是，dfs整个树，每到一个节点将该节点u加入字典树，离开时从字典树中删除
//  这样整个字典树表示的就是从u到根节点中所有的树了。
//  又一个关键是，怎么对字典树进行动态更改？
//  这又是一个新技巧。我们对每个节点增加一个cnt值，表示这个节点以下有多少个树。cnt>0表示节点有效，cnt=0的话，我们就不去遍历他了。
//  val表示字典树中一个节点代表的值，cnt表示这个节点下有多少数字
//  g存每个节点u有哪些子节点
//  mp存储对每个节点u，存在哪些查询 以及这个查询在queries中对应的索引
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int val, cnt;
        node* child[2];
        node (int _val, int _cnt) {
            val = _val;
            cnt = _cnt;
            memset(child, 0, sizeof(child));
        }
    };
    int root;
    vector<int> g[100010];
    vector<int> res;
    vector<pair<int, int>> mp[100010];
    node* trie;
    void dfs(int u) {
        node* tmp = trie;
        tmp->cnt++;
        //  insert u
        for (int k = 20; k >= 0; k--) {
            int bit = (u >> k) & 1, v = tmp->val, c = tmp->cnt;
            if (tmp->child[bit]) {
                tmp = tmp->child[bit];
                tmp->cnt++;
            }
            else {
                tmp->child[bit] = new node(2 * v + bit, 1);
                tmp = tmp->child[bit];
            }
        }
        //  compute val of u query
        for (auto pi: mp[u]) {
            tmp = trie;
            int q = pi.first, ind = pi.second;
            for (int k = 20; k >= 0; k--) {
                int bit = (q >> k) & 1;
                if (tmp->child[bit ^ 1] && tmp->child[bit ^ 1]->cnt > 0) {
                    tmp = tmp->child[bit ^ 1];
                } else {
                    tmp = tmp->child[bit];
                }
            }
            res[ind] = tmp->val ^ q;
        }
        for (int v: g[u]) dfs(v);
        //  pop u
        tmp = trie;
        for (int k = 20; k >= 0; k--) {
            int bit = (u >> k) & 1;
            tmp = tmp->child[bit];
            tmp->cnt--;
        }
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1) {
                root = i;
                continue;
            }
            g[parents[i]].push_back(i);
        }
        int m = queries.size();
        res.resize(m);
        for (int i = 0; i < m; i++) {
            mp[queries[i][0]].push_back({queries[i][1], i});
        }
        trie = new node(0, 0);
        dfs(root);
        return res;
    }
};
