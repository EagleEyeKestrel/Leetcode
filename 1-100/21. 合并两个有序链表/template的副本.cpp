//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *now = dummy, *p1 = list1, *p2 = list2;
        while (p1 || p2) {
            int v1 = p1 ? p1->val : INT_MAX;
            int v2 = p2 ? p2->val : INT_MAX;
            ListNode *node = new ListNode();
            if (v1 <= v2) {
                node->val = v1;
                p1 = p1->next;
            } else {
                node->val = v2;
                p2 = p2->next;
            }
            now->next = node;
            now = node;
        }
        return dummy->next;
    }
};