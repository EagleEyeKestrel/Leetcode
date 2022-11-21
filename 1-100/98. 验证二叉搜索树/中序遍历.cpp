//
//  main.cpp
//  注意不能is_sorted，可能会有重复元素
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
    vector<int> seq;
    void dfs(TreeNode *node) {
        if (!node)
            return;
        dfs(node->left);
        seq.push_back(node->val);
        dfs(node->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for (int i = 1; i < seq.size(); i++) {
            if (seq[i] <= seq[i - 1]) {
                return false;
            }
        }
        return true;
    }
};