//
//  main.cpp
//  完美二叉树的话就简单多了，直接递归
//  connect处理root的左右儿子
//  left的next一定存在是right，right的next是否存在要看root->next
//  Copyright © 2020 ji luyang. All rights reserved.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root;
        root->left->next = root->right;
        if(root->next) root->right->next = root->next->left;
        connect(root->right);
        connect(root->left);
        return root;
    }
};
