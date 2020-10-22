//
//  main.cpp
//  标准的链表操作应该是，快慢指针找中点，然后第二段反转，然后两段一起判断，看有没有不符合的点
//  这里分下来第一段的长度是<=第二段的，不影响
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head, *slow = head, *pre = NULL;
        while(fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;

        ListNode* dummy = new ListNode(-1);
        dummy->next = slow;
        ListNode* cur = slow->next;
        while(cur) {
            ListNode* nextcur = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            slow->next = nextcur;
            cur = nextcur;
        }

        ListNode* p1 = head, *p2 = dummy->next;
        while(p1 && p2) {
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
