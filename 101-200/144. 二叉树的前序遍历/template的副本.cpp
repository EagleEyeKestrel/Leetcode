//
//  main.cpp
//  和中序的迭代思路类似，now表示当前遍历子树
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* now = root;
        stack<TreeNode*> s;
        while(!s.empty() || now) {
            if(now) {
                res.push_back(now->val);
                if(now->right) s.push(now->right);
                now = now->left;
            } else {
                TreeNode* tmp = s.top();
                s.pop();
                now = tmp;
            }
        }
        return res;
    }
};
