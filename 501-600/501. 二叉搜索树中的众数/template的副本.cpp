//
//  main.cpp
//  中序遍历一遍，也不需要存序列，遍历的时候因为元素也是从小到大，记录一下当前次数即可
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
    int maxcnt = 0, nowcnt = 1;
    int last = -1;
    vector<int> res;
    void dfs(TreeNode* root) {
        if(!root) return ;
        dfs(root->left);
        if(root->val == last) {
            nowcnt++;
        } else {
            nowcnt = 1;
        }
        if(nowcnt > maxcnt) {
            maxcnt = nowcnt;
            res.clear();
            res.push_back(root->val);
        } else if(nowcnt == maxcnt) {
            res.push_back(root->val);
        }
        last = root->val;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};
