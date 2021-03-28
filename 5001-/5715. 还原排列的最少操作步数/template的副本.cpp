//
//  main.cpp
//  一次操作的f(i)=2i mod (n-1)，等价于寻找2^res == 1 mod n - 1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) return 1;
        int res = 1, x = 2;
        while (1) {
            res++, x = (x * 2) % (n - 1);
            if (x % (n - 1) == 1) break;
        }
        return res;
    }
};
