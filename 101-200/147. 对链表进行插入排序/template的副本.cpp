//
//  main.cpp
//  dummy领导一段已排序的，然后head领导一段未排序的
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(head) {
            ListNode* nextnode = head->next;
            cur = dummy;
            while(cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = nextnode;
        }
        return dummy->next;
    }
};
