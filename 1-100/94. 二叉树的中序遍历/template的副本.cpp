//
//  main.cpp
//  稀里糊涂写了个迭代法。now表示当前迭代的是now子树。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* now = root;
        while(!s.empty() || now) {
            if(now) {
                s.push(now);
                now = now->left;
            } else {
                TreeNode* tmp = s.top();
                s.pop();
                res.push_back(tmp->val);
                now = tmp->right;
            }
        }
        return res;
    }
};
