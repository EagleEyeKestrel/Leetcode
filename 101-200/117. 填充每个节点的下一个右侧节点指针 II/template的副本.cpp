//
//  main.cpp
//  永远不会忘记的题。。当时递归先递归了root->left，然后画那个破样例画了个把小时
//  connect root处理root的左右节点的next指针，此时需要右侧的上一层节点next指针已经填完
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
        if(!root) return NULL;
        if(root->left) {
            if(root->right) root->left->next = root->right;
            else {
                Node* now = root->next;
                while(now) {
                    if(now->left) {
                        root->left->next = now->left;
                        break;
                    } else if(now->right) {
                        root->left->next = now->right;
                        break;
                    } else {
                        now = now->next;
                    }
                }
            }
        }
        if(root->right) {
            Node* now = root->next;
            while(now) {
                if(now->left) {
                    root->right->next = now->left;
                    break;
                } else if(now->right) {
                    root->right->next = now->right;
                    break;
                } else {
                    now = now ->next;
                }
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
