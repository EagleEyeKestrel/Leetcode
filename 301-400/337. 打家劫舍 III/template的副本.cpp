//
//  main.cpp
//  用f(root)返回一个pair，表示偷root / 不偷root能获得的最大分数，就能递归下去了
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
    pair<int, int> f(TreeNode* root) {
        if (!root) return { 0, 0 };
        auto l = f(root->left), r = f(root->right);
        int val1 = root->val + l.second + r.second;
        int val2 = max(l.first, l.second) + max(r.first, r.second);
        return { val1, val2 };
    }
    int rob(TreeNode* root) {
        auto res = f(root);
        return max(res.first, res.second);
    }
};
