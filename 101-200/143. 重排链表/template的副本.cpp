//
//  main.cpp
//  如果纯用链表操作实现，是很考验链表基本功的一道题
//  快慢指针找中点然后断开
//  反转第二段链表。再插入到第一段链表里，一共三个部分
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* dummy1 = new ListNode(), *dummy2 = new ListNode(), *dummy = new ListNode();
        ListNode* p1 = head, *p2 = head, *p = head;
        while(p2 && p2->next) {
            p = p1;
            p2 = p2->next->next;
            p1 = p1->next;
        }
        if(p2) {
            dummy2->next = p1->next;
            p1->next = NULL;
        } else {
            dummy2->next = p1;
            p->next = NULL;
        }
        dummy1->next = head;

        p = dummy2->next->next;
        ListNode* pre = dummy2->next;
        while(p) {
            ListNode* nextp = p->next;
            p->next = dummy2->next;
            dummy2->next = p;
            pre->next = nextp;
            p = nextp;
        }
        
        p1 = dummy1->next, p2 = dummy2->next;
        while(p1 && p2) {
            ListNode* nextp2 = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = nextp2;
        }
    }
};
