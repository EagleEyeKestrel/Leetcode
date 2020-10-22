//
//  main.cpp
//  这是一个比较容易想到的写法，dfs返回root子树是否含有1
//  然后root子树里对左右子树进行操作
//  注意要排除只有[0]的情况
//  其实也可以只用一个函数实现，原理其实也差不多
//  Copyright © 2020 ji luyang. All rights reserved.
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
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int resl = dfs(root->left), resr = dfs(root->right);
        if(!resl) root->left = NULL;
        if(!resr) root->right = NULL;
        return root->val || resl || resr;
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(!root || (!root->val && !root->left && !root->right)) return NULL;
        return root;
    }
};
