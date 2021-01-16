//
//  main.cpp
//  老实说，没想到
//  如果str1 = mx, str2 = nx, 那么str1 + str2 == str2 + str1
//  如果相等，那结果就是长度的最大公约数
//  碰到循环字符串，要想到上述这样的加法实现
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
