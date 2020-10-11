//
//  main.cpp
//  在中序遍历的过程中计算相邻差，取最小值
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
    int pre = -1;
    int res = INT_MAX;
    void dfs(TreeNode* root) {
        if(!root) return ;
        dfs(root->left);
        if(pre != -1) res = min(res, root->val - pre);
        pre = root->val;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }
};
