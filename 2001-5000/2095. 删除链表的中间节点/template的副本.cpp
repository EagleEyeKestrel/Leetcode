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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        int cnt = 0;
        ListNode *now = head;
        while (now) {
            cnt++;
            now = now->next;
        }
        now = head;
        ListNode *pre = dummy;
        for (int i = 0; i < cnt / 2; i++) {
            pre = now;
            now = now->next;
        }
        pre->next = now->next;
        return dummy->next;
    }
};
