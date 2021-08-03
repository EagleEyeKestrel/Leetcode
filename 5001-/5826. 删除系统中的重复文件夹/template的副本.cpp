//
//  main.cpp
//  最大的问题在于怎么表示 子树完全相同这个概念？
//  这里采用括号嵌套的形式，在每个节点存储子树的内容
//  结构体node中，name是该节点的名字，str是子树的内容，child是所有儿子
//  mp是儿子的名字与节点的映射
//  第一步，建树；第二步，dfs树，在遍历过程中得到每个节点的str，并对每个str计数
//  第三步，遍历所有路径，检查每个节点str的计数。如果发现某个节点str计数大于1，说明这个节点的子树是重复的，就不加到结果中了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        string name, str;
        vector<node*> child;
        unordered_map<string, node*> mp;
    };
    node* root;
    unordered_map<string, int> dict;
    void dfs(node* p) {
        if (p == nullptr) return;
        for (node* son: p->child) {
            dfs(son);
        }
        for (node* son: p->child) {
            p->str += son->name;
            p->str.push_back('(');
            p->str += son->str;
            p->str.push_back(')');
        }
        if (p->str.size()) {
            dict[p->str]++;
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new node();
        for (auto &path: paths) {
            node* tmp = root;
            for (string &s: path) {
                if (!tmp->mp.count(s)) {
                    node* newson = new node();
                    tmp->child.push_back(newson);
                    tmp->mp[s] = newson;
                    newson->name = s;
                }
                tmp = tmp->mp[s];
            }
        }
        dfs(root);
        vector<vector<string>> res;
        for (auto &path: paths) {
            node* tmp = root;
            int flag = 1;
            for (string &s: path) {
                tmp = tmp->mp[s];
                if (dict[tmp->str] > 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(path);
        }
        return res;
    }
};
