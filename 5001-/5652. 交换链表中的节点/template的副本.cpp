//
//  main.cpp
//
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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        ListNode* node1 = head, *node2 = head;
        for (int i = 0; i < k - 1; i++) node1 = node1->next;
        for (int i = 0; i < n - k; i++) node2 = node2->next;
        int cur = node1->val;
        node1->val = node2->val;
        node2->val = cur;
        return head;
    }
};
