//
//  main.cpp
//  后序遍历的迭代法是三种里面最难的了
//  其实模拟人脑的思维方式。now表示的是当前遍历的是now子树
//  我们人脑遍历的时候就是跑到最左，直到叶子结点为止，这就是if的第一个情形
//  第二种情况，子节点都遍历完了，这个时候维护一个last，当now的儿子就是last时，说明子节点遍历结束
//  此时说明已经轮到now。然后else里，如果有子节点肯定先去子节点。
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode* last = root;
        vector<int> res;
        stack<TreeNode*> s;
        s.push(last);
        while(!s.empty()) {
            TreeNode* now = s.top();
            if((!now->left && !now->right) || now->left == last || now->right == last) {
                res.push_back(now->val);
                s.pop();
                last = now;
            } else {
                if(now->right) s.push(now->right);
                if(now->left) s.push(now->left);
            }
        }
        return res;
    }
};
