//
//  main.cpp
//  朴素做就行了，当然其实符合条件的n是质数的平方
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) cnt++;
        }
        return cnt == 3;
    }
};
