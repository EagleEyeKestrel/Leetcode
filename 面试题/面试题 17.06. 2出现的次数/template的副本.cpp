//
//  main.cpp
//  last表示后面已经处理了10的几次方，remain表示后面的余数
//  比如12345 678，此时n=12345，last=1000，remain=678
//  此时考虑5这一位的2，从00000-12340，出现了1234/10次的2，然后考虑5>2，加上last一次
//  如果等于2，那要加上remain+1，而不是last。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOf2sInRange(int n) {
        long res = 0, last = 1, remain = 0;
        while (n) {
            res += n / 10 * last;
            if (n % 10 == 2) res += remain + 1;
            if (n % 10 > 2) res += last;
            remain = n % 10 * last + remain;
            last *= 10;
            n /= 10;
        }
        return res;
    }
};
