//
//  main.cpp
//  穷举一下a就可以了，注意下不要越界
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; (long)a * a <= c; a++) {
            int b2 = c - a * a;
            int b = sqrt(b2);
            if (b * b + a * a == c) return true;
        }
        return false;
    }
};
