//
//  main.cpp
//  按照正常思路来就可以过了，先bfs，然后逐层判断一下
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
    vector<vector<int>> v;
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> alevel;
            for(int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                alevel.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            v.push_back(alevel);
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        bfs(root);
        int n = v.size();
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < v[i].size(); j++) {
                    if(v[i][j] % 2 == 0 || (j > 0 && v[i][j] <= v[i][j - 1])) return false;
                }
            } else {
                for(int j = 0; j < v[i].size(); j++) {
                    if(v[i][j] % 2 || (j > 0 && v[i][j] >= v[i][j - 1])) return false;
                }
            }
        }
        return true;
    }
};
