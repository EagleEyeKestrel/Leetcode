//
//  main.cpp
//  原来是三项，看了半天哪里错了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) return !!n;
        int a = 0, b = 1, c = 1, d;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};
