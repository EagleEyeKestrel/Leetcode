//
//  main.cpp
//  简单题，注意判断一下非正数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        return num == 1;
    }
};
