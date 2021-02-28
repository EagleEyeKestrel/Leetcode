//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int strToInt(string str) {
        if (str.empty()) return 0;
        int i = 0, sign = 1, num = 0, n = str.size();
        while (i < n && str[i] == ' ') i++;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') sign = -1;
            i++;
        }
        while (i < n && isdigit(str[i])) {
            if (num > INT_MAX / 10 || num == INT_MAX / 10 && str[i] >= '8') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 - '0' + str[i];
            i++;
        }
        return sign * num;
    }
};
