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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *now = dummy;
        int carry = 0;
        while (p1 || p2 || carry > 0) {
            int a = (p1 ? p1->val : 0);
            int b = (p2 ? p2->val : 0);
            ListNode *node = new ListNode((a + b + carry) % 10);
            now->next = node;
            now = node;
            carry = (a + b + carry) / 10;
            p1 = p1 ? p1->next : p1;
            p2 = p2 ? p2->next : p2;
        }
        return dummy->next;
    }
};
