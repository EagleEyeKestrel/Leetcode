//
//  main.cpp
//  看上去是lca，其实不需要。先找到两个点到树根的路径
//  然后比对找到LCA，然后一个个找就可以了。主要是代码细节
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
    int p[100010];
    map<int, TreeNode*> mp;
    void dfs(TreeNode *node, int fa) {
        if (!node) return;
        p[node->val] = fa;
        mp[node->val] = node;
        dfs(node->left, node->val);
        dfs(node->right, node->val);
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, -1);
        vector<int> v1, v2;
        int now = startValue;
        while (now != -1) {
            v1.push_back(now);
            now = p[now];
        }
        now = destValue;
        while (now != -1) {
            v2.push_back(now);
            now = p[now];
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        now = 0;
        while (now + 1 < v1.size() && now + 1 < v2.size() && v1[now + 1] == v2[now + 1]) now++;
        int LCA = v1[now];
        string res;
        for (int i = 0; i < v1.size() - now - 1; i++) res.push_back('U');
        TreeNode *nownode = mp[LCA];
        while (nownode->val != destValue) {
            if (nownode->left && nownode->left->val == v2[now + 1]) {
                nownode = nownode->left;
                res.push_back('L');
            } else {
                nownode = nownode->right;
                res.push_back('R');
            }
            now++;
        }
        return res;
    }
};
