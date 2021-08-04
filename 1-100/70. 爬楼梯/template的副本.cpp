//
//  main.cpp
//  最经典的dp问题，可以优化到O(1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
