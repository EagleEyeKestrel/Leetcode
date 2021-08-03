//
//  main.cpp
//  显然要分离出尽可能多的3
//  要注意这里一定要大于1段，所以边界条件要处理一下
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        if (n == 4) return 4;
        int res = 1;
        while (n >= 5) {
            res *= 3;
            n -= 3;
        }
        return n * res;
    }
};
