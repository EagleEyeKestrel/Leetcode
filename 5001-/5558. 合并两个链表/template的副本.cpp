//
//  main.cpp
//  找到apre和bnext，然后连接到list2
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* apre = list1, *bnext = list1;
        for(int i = 0; i < a - 1; i++) apre = apre->next;
        for(int i = 0; i < b + 1; i++) bnext = bnext->next;
        apre->next = list2;
        ListNode* now = list2;
        while(now->next) now = now->next;
        now->next = bnext;
        return list1;
    }
};
