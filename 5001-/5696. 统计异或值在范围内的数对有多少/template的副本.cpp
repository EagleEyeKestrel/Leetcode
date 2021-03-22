//
//  main.cpp
//  参考了lucifer1004的题解
//  异或的题，要能想到trie树，符合贪心异或的原则
//  val记录这个点的bit，cnt记录这个节点下有多少值
//  一方面，dfs的时候，走异或值为0的点，如果接下来的最大值都不会超过v，那么直接加上这个子树里的所有值。或者就走异或值为1的点
//  另一方面，count(v)会重复记录num XOR num的情况（和自己）
//  但不用管，相减之后都没了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int val, cnt;
        node* childs[2];
        node (int _v, int _c) {
            val = _v, cnt = _c;
            memset(childs, 0, sizeof(childs));
        }
    };
    node* root;
    void insert(int num) {
        node* tmp = root;
        for (int k = 15; k >= 0; k--) {
            int bit = (num >> k) & 1;
            if (!tmp->childs[bit]) tmp->childs[bit] = new node(bit, 0);
            tmp = tmp->childs[bit];
            tmp->cnt++;
        }
    }
    int dfs(node* p, int now, int num, int k, int v) {
        int bit = (num >> k) & 1, res = 0;
        if (p->childs[bit]) {
            if ((now ^ (1 << k)) - 1 <= v) res += p->childs[bit]->cnt;
            else res += dfs(p->childs[bit], now, num, k - 1, v);
        }
        if (p->childs[1 - bit]) {
            if ((now ^ (1 << k)) <= v) res += dfs(p->childs[1 - bit], now ^ (1 << k), num, k - 1, v);
        }
        return res;
    }
    int f(vector<int>& nums, int v) {
        int res = 0;
        for (int num: nums) {
            res += dfs(root, 0, num, 15, v);
        }
        return res;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        root = new node(0, 0);
        for (int num: nums) {
            insert(num);
        }
        return (f(nums, high) - f(nums, low - 1)) / 2;
    }
};
