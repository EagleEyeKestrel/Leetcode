//
//  main.cpp
//  从最大点开始遍历，用一个变量维护更大点的值之和
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
    int nowSum = 0;
    void dfs(TreeNode* root) {
        if(!root) return ;
        dfs(root->right);
        root->val += nowSum;
        nowSum += (root->val - nowSum);
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
