//
//  main.cpp
//  在中序遍历中去改变节点的指向
//  同样这里也可以使用dummy作为头节点的技巧
//  Copyright © 2021 ji luyang. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        res->right = root;
        root->left = NULL;
        res = root;
        inOrder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        res = dummy;
        inOrder(root);
        return dummy->right;
    }
};
