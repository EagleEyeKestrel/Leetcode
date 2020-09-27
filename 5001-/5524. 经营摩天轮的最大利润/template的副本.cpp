//
//  main.cpp
//  好无聊的题。。就是阅读理解，每上一批人算一批利润
//  就是没明白为什么可以把人吊在半空中？
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size(), maxv = -1, now = 0, rest = 0, res = -1, i = 0;
        for(; i < n; i++) {
            rest += customers[i];
            int up = min(rest, 4);
            rest -= up;
            now = now + up * boardingCost - runningCost;
            if(now > maxv) {
                maxv = now;
                res = i + 1;
            }
        }
        i--;
        while(rest > 0) {
            i++;
            int up = min(rest, 4);
            rest -= up;
            now = now + up * boardingCost - runningCost;
            if(now > maxv) {
                maxv = now;
                res = i + 1;
            }
        }
        return res;
    }
};
