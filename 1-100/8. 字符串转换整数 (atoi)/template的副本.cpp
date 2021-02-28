//
//  main.cpp
//  没啥思维质量，主要是边界条件的处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        int i = 0, sign = 1, num = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            if (num > INT_MAX / 10 || num == INT_MAX / 10 && s[i] >= '8') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 - '0' + s[i];
            i++;
        }
        return sign * num;
    }
};
