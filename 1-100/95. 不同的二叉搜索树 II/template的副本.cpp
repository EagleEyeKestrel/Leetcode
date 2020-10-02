//
//  main.cpp
//  用build(l, r)返回l到r区间内的所有可能的二叉搜索树，暴力递归即可
//  Copyright © 2020 ji luyang. All rights reserved.
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
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>();
        return build(1, n);
    }
    vector<TreeNode*> build(int l, int r) {
        vector<TreeNode*> res;
        if(l > r) {
            res.push_back(NULL);
            return res;
        }
        if(l == r) {
            TreeNode* tmp = new TreeNode(l);
            res.push_back(tmp);
            return res;
        }
        for(int mid = l; mid <= r; mid++) {
            auto lchild = build(l, mid - 1);
            auto rchild = build(mid + 1, r);
            for(TreeNode* lroot: lchild) {
                for(TreeNode* rroot: rchild) {
                    TreeNode* root = new TreeNode(mid);
                    root->left = lroot;
                    root->right = rroot;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
