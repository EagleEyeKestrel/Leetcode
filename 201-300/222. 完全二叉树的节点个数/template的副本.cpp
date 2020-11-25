//
//  main.cpp
//  利用完全二叉树的性质，用深度可以确定一半数量
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
    int geth(TreeNode* root) {
        int res = 0;
        while(root) {
            res++;
            root = root->left;
        }
        return res;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = geth(root->left);
        int rh = geth(root->right);
        if(lh == rh) {
            return (1 << lh) + countNodes(root->right);
        } else {
            return (1 << rh) + countNodes(root->left);
        }
    }
};
