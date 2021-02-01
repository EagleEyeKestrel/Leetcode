//
//  main.cpp
//  trie树解法
//  对smalls建立一个trie树，然后穷举每个big的开始位置开始遍历
//  这里可以节省掉原来unordered_map的常数？变成了指针的遍历。大概击败30%
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        string val;
        bool end;
        node* childs[26];
        node(string &s, bool _end) {
            val = s;
            end = _end;
            memset(childs, 0, sizeof(childs));
        }
    };
    node* root;
    void insert(string& s) {
        node* tmp = root;
        for (char c: s) {
            if (tmp->childs[c - 'a'] == NULL) {
                string nows = tmp->val;
                nows.push_back(c);
                tmp->childs[c - 'a'] = new node(nows, false);
            }
            tmp = tmp->childs[c - 'a'];
        }
        tmp->end = true;
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int n = big.size(), maxl = 0;
        string empty = "";
        root = new node(empty, false);
        for (string& s: smalls) insert(s), maxl = max(maxl, (int)s.size());
        unordered_map<string, int> mp;
        for (int i = 0; i < smalls.size(); i++) mp[smalls[i]] = i;
        vector<vector<int>> res(smalls.size(), vector<int>());
        for (int i = 0; i < n; i++) {
            node* tmp = root;
            for (int j = i; j < n && j < i + maxl; j++) {
                if (tmp->childs[big[j] - 'a']) {
                    tmp = tmp->childs[big[j] - 'a'];
                } else break;
                if (tmp->end) {
                    res[mp[tmp->val]].push_back(i);
                }
            }
        }

        return res;
    }
};
