//
//  main.cpp
//  自底向上的遍历。关键是每个点有三种状态，0代表装了监视器，1代表没装但是可控，2代表无法观测
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
    int res = 0;
    int dfs(TreeNode* root) {
        if (!root) return 1;
        int l = dfs(root->left), r = dfs(root->right);
        if (l == 2 || r == 2) {
            res++;
            return 0;
        }
        if (l == 0 || r == 0) {
            return 1;
        }
        
        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        if (dfs(root) == 2) res++;
        return res;
    }
};
