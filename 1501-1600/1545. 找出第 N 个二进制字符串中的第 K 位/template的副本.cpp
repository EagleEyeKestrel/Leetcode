//
//  main.cpp
//  简单的递归，讨论k是在字符串的哪一半
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int l = pow(2, n) - 1;
        if (k <= l >> 1) return findKthBit(n - 1, k);
        if (k == (l >> 1) + 1) return '1';
        return '1' + '0' - findKthBit(n - 1, l - k + 1);
    }
};
