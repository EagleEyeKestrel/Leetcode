//
//  main.cpp
//  和面试题17.06类似，这里的写法可能更好理解一些
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long last = 1; last <= n; last *= 10) {
            int before = n / last;
            res += before / 10 * last;
            if (before % 10 == 1) res += n % last + 1;
            if (before % 10 > 1) res += last;
        }
        return res;
    }
};
