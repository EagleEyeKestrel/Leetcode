//
//  main.cpp
//  递归的时候存一下之前的数即可，对每个叶子结点求和
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
    void dfs(TreeNode* root, int tmp) {
        if(!root->left && !root->right) {
            res += tmp * 10 + root->val;
            return;
        }
        if(root->left) dfs(root->left, tmp * 10 + root->val);
        if(root->right) dfs(root->right, tmp * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return res;
    }
};
