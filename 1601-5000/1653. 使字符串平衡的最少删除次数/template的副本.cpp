//
//  main.cpp
//  用l[i]表示i左边a的个数
//  然后可以穷举...aabb...的最后一个a分界线的位置，计算res的最小值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), tmp = 0;
        int l[n + 1];
        l[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') tmp++;
            l[i + 1] = tmp;
        }
        int res = l[n];
        for (int i = 0; i < n; i++) {
            res = min(res, i + 1 - l[i + 1] + l[n] - l[i + 1]);
        }
        return res;
    }
};
