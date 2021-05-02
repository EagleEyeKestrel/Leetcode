//
//  main.cpp
//  题目不允许使用long，那么就额外判断一下最后一步反转
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x / 10) {
            int tmp = x % 10;
            res = 10 * res + tmp;
            x /= 10;
        }
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = 10 * res + x;
        return res;
    }
};
