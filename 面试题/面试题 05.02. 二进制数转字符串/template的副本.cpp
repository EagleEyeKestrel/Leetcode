//
//  main.cpp
//  但我这个算法由于double精度的限制，还是不能做到精确的转化
//  比如0.2868311060592532，只会输出32位的小数，但实际上是error
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        double tmp = 0.5;
        for (int i = 0; i < 32; i++) {
            if (num >= tmp) {
                res.push_back('1');
                num -= tmp;
                if (num < 1e-12) break;
            }
            else res.push_back('0');
            tmp /= 2;
        }
        if (num >= 1e-12) return "ERROR";
        return res;
    }
};
