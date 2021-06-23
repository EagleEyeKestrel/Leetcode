//
//  main.cpp
//  找到最后面一个奇数数字，和他之前的所有数字
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), id = -1;
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2) {
                id = i;
                break;
            }
        }
        if (id == -1) return "";
        return num.substr(0, id + 1);
    }
};
