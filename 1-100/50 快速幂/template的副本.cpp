//
//  main.cpp
//  快速幂模版。其实不用讨论n的正负的，负的也可以模
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1) return x;
        double res = 1;
        int nn = n;
        while(nn) {
            if(nn % 2) {
                res *= x;
            }
            x *= x;
            nn /= 2;
        }
        return n >= 0 ? res : 1 / res;
    }
};
