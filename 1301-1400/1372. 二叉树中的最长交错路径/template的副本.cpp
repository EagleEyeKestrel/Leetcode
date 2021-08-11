//
//  main.cpp
//  用哈希表mpl表示root往下 左拐 最长路径的长度，mpr表示右拐
//  dfs，自底向上拿到结果
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
    unordered_map<TreeNode*, int> mpl, mpr;
    int res = 0;
    void dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            mpl[root] = 0;
            mpr[root] = 0;
            return;
        }
        if (root->left) {
            dfs(root->left);
            mpl[root] = mpr[root->left] + 1;
            res = max(res, mpl[root]);
        }
        if (root->right) {
            dfs(root->right);
            mpr[root] = mpl[root->right] + 1;
            res = max(res, mpr[root]);
        }

    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return res;
    }
};
