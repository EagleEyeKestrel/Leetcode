//
//  main.cpp
//  Trie树
//  在每个节点除了维护对应的字符串，还可以维护一个大小不超过3的集合
//  存储这个节点以下的单词中，字典序前三名
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        string val;
        node* childs[26];
        set<string> rec;
        node (string& s) {
            val = s;
            memset(childs, 0, sizeof(childs));
        }
    };
    node* root;
    void insert(string s) {
        node* tmp = root;
        for (int i = 0; i < s.size(); i++) {
            if (!tmp->childs[s[i] - 'a']) {
                string ss = tmp->val;
                ss.push_back(s[i]);
                tmp->childs[s[i] - 'a'] = new node(ss);
            }
            tmp = tmp->childs[s[i] - 'a'];
            tmp->rec.insert(s);
            if (tmp->rec.size() > 3) tmp->rec.erase(*(tmp->rec.rbegin()));
        }
    }
    string emp = "";
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>> res;
        root = new node(emp);
        for (string &product: products) {
            insert(product);
        }
        node* tmp = root;
        for (int i = 0; i < searchWord.size(); i++) {
            if (!tmp->childs[searchWord[i] - 'a']) {
                tmp->childs[searchWord[i] - 'a'] = new node(emp);
            }
            tmp = tmp->childs[searchWord[i] - 'a'];
            vector<string> v(tmp->rec.begin(), tmp->rec.end());
            res.push_back(v);
        }
        return res;
    }
};
