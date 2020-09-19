//
//  main.cpp
//  遍历一下就可以了，简单题
//  Copyright © 2020 ji luyang. All rights reserved.
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
    int res = 0;
    void dfs(TreeNode* root) {
        if(!root) return ;
        if(root->left && !(root->left->left) && !(root->left->right)) {
            res += root->left->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};
