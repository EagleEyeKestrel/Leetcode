//
//  main.cpp
//  理论上用通项公式+快速幂可以达到O(logN)，这里就O(N)解决了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        int a = 0, b = 1, c;
        for(int i = 0; i < N - 1; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
