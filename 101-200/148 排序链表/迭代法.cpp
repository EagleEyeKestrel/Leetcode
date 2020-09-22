//
//  main.cpp
//  递归法，快慢指针找中点，再写个merge
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        int n = 1;
        ListNode* cur = head;
        while(cur->next) {
            cur = cur->next;
            n++;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for(int size = 1; size < n; size *= 2) {
            cur = dummy->next;
            ListNode* tail = dummy; //dummy-> ... tail-> @ -> @ ->...
            while(cur) {
                ListNode* l = cur;
                ListNode* r = cut(l, size);
                cur = cut(r, size); //dummy-> ... tail  l->@  r->@
                tail->next = merge(l, r);
                while(tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummy->next;
    }
    
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy, *p1 = l, *p2 = r;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1) p->next = p1;
        if(p2) p->next = p2;
        return dummy->next;
    }

    ListNode* cut(ListNode* head, int size) {
        ListNode* cur = head;
        while(--size) {
            if(cur) cur = cur->next;
            else break;
        }
        if(!cur) return NULL;
        ListNode* res = cur->next;
        cur->next = NULL;
        return res;
    }
};
