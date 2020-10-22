//
//  main.cpp
//  老题目了。。算日期
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string res[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    int f(int y) {
        return y % 400 == 0 || (y % 4 == 0 && y % 100);
    }
    string dayOfTheWeek(int day, int month, int year) {
        int d = 0;
        for(int y = 1971; y < year; y++) d = (d + f(y) + 365) % 7;
        for(int m = 1; m < month; m++) {
            if(m == 2) {
                d += (28 + f(year));
            } else if(m == 4 || m == 6 || m == 9 || m == 11) {
                d += 30;
            } else {
                d += 31;
            }
        }
        return res[(d + day) % 7];
    }
};
