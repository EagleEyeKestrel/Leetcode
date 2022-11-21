//
//  main.cpp
//
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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left) {
            TreeNode *r = root->right;
            root->right = root->left;
            root->left = nullptr;
            while (root->right)
                root = root->right;
            root->right = r;

        }
    }
};