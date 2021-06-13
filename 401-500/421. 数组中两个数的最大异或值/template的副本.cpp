//
//  main.cpp
//  对每一个数的二进制序列建一个树表示
//  因为异或问题是可贪心的，对于num，要得到最大的异或结果
//  每一步都尽可能走在某个bit不一样的儿子
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        node *children[2];
        node() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };
    void insert(node *root, int num) {
        node *tmp = root;
        for (int i = 30; i >= 0; i--) {
            int t = (num >> i) & 1;
            if (tmp->children[t] == nullptr) tmp->children[t] = new node();
            tmp = tmp->children[t];
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        node *root = new node();
        for (int num: nums) insert(root, num);
        int res = 0;
        for (int num: nums) {
            int ans = 0;
            node *tmp = root;
            for (int i = 30; i >= 0; i--) {
                int t = (num >> i) & 1;
                if (tmp->children[1 - t]) {
                    tmp = tmp->children[1 - t];
                    ans += (1 << i);
                } else {
                    tmp = tmp->children[t];
                }
            }
            res = max(res, ans);
        }
        return res;
    }
};
