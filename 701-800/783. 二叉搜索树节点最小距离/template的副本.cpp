//
//  main.cpp
//  中序遍历走一遍就好了
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
    TreeNode* pre = NULL;
    int res = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        if(pre) res = min(res, abs(root->val - pre->val));
        pre = root;
        dfs(root->right);
    }
};
