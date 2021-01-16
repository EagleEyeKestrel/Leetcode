//
//  main.cpp
//  贪心地减
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string intToRoman(int num) {
        int v[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, \
            10, 9, 5, 4, 1 };
        string str[13] = { "M", "CM", "D", "CD", "C", "XC", \
            "L", "XL", "X", "IX", "V", "IV", "I" };
        string res = "";
        for (int i = 0; i < 13; i++) {
            while (num >= v[i]) {
                num -= v[i];
                res += str[i];
            }
        }
        return res;
    }
};
