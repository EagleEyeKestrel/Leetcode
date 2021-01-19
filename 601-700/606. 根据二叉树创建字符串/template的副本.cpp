//
//  main.cpp
//  直接讨论t节点两个儿子的四种情况，简单明了
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
    string res;
    string tree2str(TreeNode* t) {
        if (!t) return "";
        if (!t->left && !t->right) return to_string(t->val);
        if (!t->left && t->right) return to_string(t->val) + "()(" + tree2str(t->right) + ")";
        if (t->left && !t->right) return to_string(t->val) + "(" + tree2str(t->left) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};
