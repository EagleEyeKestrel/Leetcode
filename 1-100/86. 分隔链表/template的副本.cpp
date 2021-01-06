//
//  main.cpp
//  用两个链表分别存小于 / 大于等于 x的链表，然后连起来
//  不知道为什么一定要生成newnode才能过，如果直接接在原链表上会出问题？
//  emm，不知道是不是原来哪里写错了
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1);
        ListNode* p1 = dummy1, *p2 = dummy2, *p = head;
        while (p) {
            ListNode* newnode = new ListNode(p->val);
            if (p->val < x) {
                p1->next = newnode;
                p1 = newnode;
            } else {
                p2->next = newnode;
                p2 = newnode;
            }
            p = p->next;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
