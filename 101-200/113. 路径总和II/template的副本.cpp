//
//  main.cpp
//  简单的递归，递归的时候记录一下当前路径就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int> &tmp, int sum){
        if(!root) return ;
        tmp.push_back(root->val);
        if(root->val == sum && (root->left == NULL && root->right == NULL)) {
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(root->left, tmp, sum-root->val);
        dfs(root->right, tmp, sum-root->val);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dfs(root, tmp, sum);
        return res;
    }
};
