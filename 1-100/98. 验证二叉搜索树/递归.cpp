//
//  main.cpp
//  本题数据恶意卡int。笑死
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
    bool f(TreeNode *node, long long l, long long r) {
        if (!node)
            return true;
        if (node->val < l || node->val > r)
            return false;
        return f(node->left, l, 1LL * node->val - 1) && f(node->right, 1LL * node->val + 1, r);
    }
    bool isValidBST(TreeNode* root) {
        return f(root, -1e18, 1e18);
    }
};