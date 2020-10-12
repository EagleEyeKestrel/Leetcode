//
//  main.cpp
//  边遍历就可以边交换了，两个node为一组
//  cur记录当前组的第一个元素，pre记录之前一组的末尾
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head, *pre = dummy;
        while(cur && cur->next) {
            ListNode* nextnode = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = nextnode;
            pre = cur;
            cur = nextnode;
        }
        if(cur) pre->next = cur;
        return dummy->next;
    }
};
