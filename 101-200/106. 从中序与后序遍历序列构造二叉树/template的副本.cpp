//
//  main.cpp
//  基本题，居然还卡了两下。。l和r标记的是在inorder里的范围
//  一方面，now用完就--，至于有没有l==r，都可以，有了略快一点
//  另一方面，现在是后序！一定要先递归right
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
    int now;
    unordered_map<int, int> m;
    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if(l > r) return NULL;
        TreeNode* tmp = new TreeNode(postorder[now--]);
        //if(l == r) return tmp;
        int mid = m[postorder[now + 1]];
        tmp->right = f(inorder, postorder, mid + 1, r);
        tmp->left = f(inorder, postorder, l, mid - 1);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        now = n - 1;
        for(int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return f(inorder, postorder, 0, n - 1);
    }
};
