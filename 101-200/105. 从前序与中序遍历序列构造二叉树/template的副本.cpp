//
//  main.cpp
//
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
    unordered_map<int, int> m;
    int now = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(!n) return NULL;
        for(int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1);
    }
    TreeNode* build(vector<int>& preorder,int l,int r) {
        if(l > r) return NULL;
        TreeNode* tmp = new TreeNode(preorder[now++]);
        //if(l == r) return tmp;
        int mid = m[tmp->val];
        tmp->left = build(preorder, l, mid - 1);
        tmp->right = build(preorder, mid + 1, r);
        return tmp;
    }
};
