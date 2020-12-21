//
//  main.cpp
//  bfs，然后对奇数索引行反转一下
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            while (n--) {
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(v);
        }
        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
