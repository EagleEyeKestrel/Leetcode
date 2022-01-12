//
//  main.cpp
//  好久没写链表题了，写了个空间O(1)的
//  注意是偶数长度的组，不是第偶数个组。。
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
    pair<ListNode*, ListNode*> inv(ListNode *head, ListNode *tail) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *now = head->next;
        tail->next = nullptr;
        while (now) {
            ListNode *nextnode = now->next;
            now->next = dummy->next;
            dummy->next = now;
            head->next = nextnode;
            now = nextnode;
        }
        return {dummy->next, head};
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int id = 0, group = 0;
        ListNode *now = head, *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy;
        while (now) {
            group++;
            ListNode *start = now, *end = now;
            int len = 1;
            for (int i = 0; i < group - 1 && end->next; i++) end = end->next, len++;
            ListNode *nextstart = end->next;
            if (len % 2) {
                now = nextstart;
                pre = end;
                continue;
            }
            auto pi = inv(start, end);
            pre->next = pi.first;
            pi.second->next = nextstart;
            now = nextstart;
            pre = start;
        }
        return dummy->next;
    }
};
