//
//  main.cpp
//  这个题不难，后序遍历一下就好了
//  mp记录一个节点的子树是不是bst。sum记录子树节点和
//  注意flag需要&=左右节点的mp，不只是看左右节点的值，还要看左右子树
//  dfs返回一个节点子树的最小，最大值
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
    unordered_map<TreeNode*, int> mp, sum;
    int res = 0;
    pair<int, int> dfs(TreeNode *root) {
        int flag = 1, mn = root->val, mx = root->val, s = root->val;
        if (root->left) {
            auto tmp = dfs(root->left);
            if (tmp.second >= root->val) flag = 0;
            flag &= mp[root->left];
            mn = min(mn, tmp.first);
            mx = max(mx, tmp.second);
            s += sum[root->left];
        }
        if (root->right) {
            auto tmp = dfs(root->right);
            if (tmp.first <= root->val) flag = 0;
            flag &= mp[root->right];
            mn = min(mn, tmp.first);
            mx = max(mx, tmp.second);
            s += sum[root->right];
        }
        mp[root] = flag;
        sum[root] = s;
        if (flag) res = max(res, s);
        return {mn, mx};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};
