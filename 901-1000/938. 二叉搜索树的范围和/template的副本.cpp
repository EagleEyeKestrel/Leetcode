//
//  main.cpp
//  简单的递归，如果发现某个子树不可能在某个范围内，就可以剪枝
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int res = 0;
        if (root->val >= low && root->val <= high) res += root->val;
        if (root->val > low) res += rangeSumBST(root->left, low, high);
        if (root->val < high) res += rangeSumBST(root->right, low, high);
        return res;
    }
};
