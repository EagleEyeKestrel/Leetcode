//
//  main.cpp
//  贪心，每次-3即可。当然dp也可以，对于dp[i],穷举从1到根号n的因数。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int a[5] = {0, 0, 2, 3, 4};
        int res = 1;
        while(n > 4) {
            n -= 3;
            res *= 3;
        }
        return res * a[n];
    }
};
