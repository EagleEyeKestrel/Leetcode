//
//  main.cpp
//  通过写每一层通项公式的形式，可以得到第i层有12x^2个苹果
//  可以遍历求解，或者可以写个求和 然后二分
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long s = 0, res = 1;
        while (1) {
            s += 12 * res * res;
            if (s >= neededApples) break;
            res++;
        }
        return 8 * res;
    }
};
