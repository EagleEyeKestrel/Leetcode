//
//  main.cpp
//  想了一会儿。其实就是对于一个BST，第一个元素必定是树根，然后递归处理出左/右子树的序列
//  只要这二者内部顺序不变，可以彼此错开。
//  递归得到左右子树的结果，然后用f递归搜索所有可能的序列
//  Copyright © 2021 ji luyang. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(vector<int> &l, vector<int> &r, vector<int> &tmp, int p1, int p2, vector<vector<int>> &res) {
        if (p1 == l.size() && p2 == r.size()) {
            res.push_back(tmp);
            return;
        }
        if (p1 < l.size()) {
            tmp.push_back(l[p1]);
            f(l, r, tmp, p1 + 1, p2, res);
            tmp.pop_back();
        }
        if (p2 < r.size()) {
            tmp.push_back(r[p2]);
            f(l, r, tmp, p1, p2 + 1, res);
            tmp.pop_back();
        }
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return {{}};
        auto l = BSTSequences(root->left), r = BSTSequences(root->right);
        for (auto &lv: l) {
            for (auto &rv: r) {
                vector<int> tmp = {root->val};
                f(lv, rv, tmp, 0, 0, res);
            }
        }
        return res;
    }
};
