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
        if(!head || !head->next) {
            return head;
        }
        ListNode* fast = head, *slow = head, *pre = NULL;
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            pre = slow;
            slow = slow -> next;
        }
        pre -> next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        while(p1 && p2) {
            if(p1 -> val < p2 -> val) {
                cur -> next = p1;
                p1 = p1 -> next;
            }
            else {
                cur -> next = p2;
                p2 = p2 -> next;
            }
            cur = cur -> next;
        }
        if(p1) cur -> next = p1;
        if(p2) cur -> next = p2;
        return dummy -> next;
    }
};
