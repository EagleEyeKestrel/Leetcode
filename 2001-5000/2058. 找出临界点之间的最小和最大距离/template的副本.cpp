//
//  main.cpp
//  基础的遍历链表操作
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v, a;
        ListNode* now = head;
        while (now) {
            v.push_back(now->val);
            now = now->next;
        }
        int n = v.size();
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1] || v[i] < v[i - 1] && v[i] < v[i + 1]) a.push_back(i);
        }
        if (a.size() < 2) return {-1, -1};
        n = a.size();
        vector<int> res = {INT_MAX, a.back() - a[0]};
        for (int i = 1; i < n; i++) res[0] = min(res[0], a[i] - a[i - 1]);
        return res;
    }
};
