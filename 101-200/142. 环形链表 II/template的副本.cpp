//
//  main.cpp
//  经典题，快慢指针相遇后，可以证明，快指针从头开始走，慢指针从相遇点继续走，每个都走一步，会在环入口相遇
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(!fast || !fast->next) return NULL;
        fast = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
