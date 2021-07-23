//
//  main.cpp
//  先由拉格朗日四平方定理检查是否只能是4个数之和
//  然后检查是否可以由1个/2个组成，如果不行，那一定是3个
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int i = 1; i <= 100; i++) if (i * i == n) return 1;
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                if (i * i + j * j == n) return 2;
            }
        }
        return 3;
    }
};
