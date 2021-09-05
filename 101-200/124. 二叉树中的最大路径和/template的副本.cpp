//
//  main.cpp
//  用dfs(root)表示：包含root且以root为顶，往下只走一条路 能得到的最大路径值
//  本来想对一个root返回一个pair表示走左/右的最大值，然后发现其实只需要返回一个最大值即可
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
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        res = max(res, root->val + max(l, 0) + max(r, 0));
        return max(0, max(l, r)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
