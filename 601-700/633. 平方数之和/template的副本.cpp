//
//  main.cpp
//  穷举一下a就可以了，注意下不要越界
//  看了一下答案大多数用双指针，l = 0, r = 根号c，左右逼近
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
