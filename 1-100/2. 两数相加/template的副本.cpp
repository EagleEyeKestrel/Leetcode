//
//  main.cpp
//  两数相加，链表操作的基本题啦。
//  dummy节点的技巧。然后p1 || p2的技巧可以免去讨论。最后别忘了处理进位
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* p1 = l1, *p2 = l2;
        int c = 0;
        while(p1 || p2) {
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;
            int d = (a + b + c) % 10;
            c = (a + b + c) / 10;
            ListNode* newNode = new ListNode(d);
            cur->next = newNode;
            cur = newNode;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        if(c) {
            ListNode* newNode = new ListNode(c);
            cur->next = newNode;
        }
        return dummy->next;
    }
};
