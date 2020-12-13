//
//  main.cpp
//  贪心
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int x: bills) {
            if(x == 20) twenty++;
            if(x == 10) ten++;
            if(x == 5) five++;
            int re = x - 5;
            while(twenty && re >= 20) {
                twenty--;
                re -= 20;
            }
            while(ten && re >= 10) {
                ten--;
                re -= 10;
            }
            while(five && re >= 5) {
                five--;
                re -= 5;
            }
            if(re) return false;
        }
        return true;
    }
};
