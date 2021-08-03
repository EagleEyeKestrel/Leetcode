//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n) {
            int tmp = n % k;
            res += tmp;
            n /= k;
        }
        return res;
    }
};
