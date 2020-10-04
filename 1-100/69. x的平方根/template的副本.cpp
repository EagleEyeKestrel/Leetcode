//
//  main.cpp
//  牛顿迭代法。其实这个now == last我觉得有点问题
//  要么改成eps < 1e-6， 要么可以从x开始，直到now * now <= x
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        double last = 1;
        while(1) {
            double now = (last + x / last) / 2;
            if(now == last) return last;
            last = now;
        }
        return 0;
    }
};
