//
//  main.cpp
//  现在个人用这种struct然后内置重载大小于号的比较多
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
    struct node {
        ListNode *ptr;
        int val;
        node (ListNode *p, int v) {
            ptr = p, val = v;
        }
        bool operator > (const node &nn) const {
            return val > nn.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *dummy = new ListNode();
        ListNode *now = dummy;
        priority_queue<node, vector<node>, greater<node>> pq;
        for (ListNode *head: lists) {
            if (head) {
                pq.push(node(head, head->val));
            }
        }
        while (!pq.empty()) {
            node p = pq.top();
            pq.pop();
            now->next = new ListNode(p.ptr->val);
            now = now->next;
            if (p.ptr->next) {
                pq.push(node(p.ptr->next, p.ptr->next->val));
            }
        }
        return dummy->next;
    }
};