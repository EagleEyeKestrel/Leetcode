//
//  main.cpp
//  利用n & (n - 1)可以消去最后一个1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};
