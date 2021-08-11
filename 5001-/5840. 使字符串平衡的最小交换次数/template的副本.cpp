//
//  main.cpp
//  记右括号比左括号多的最大值是d，那么结果就是(d+1)/2。因为最优的交换策略就是拿最右边的[换最左边的]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSwaps(string s) {
        int d = 0, l = 0, r = 0;
        for (char c: s) {
            if (c == '[') l++;
            else r++;
            d = max(d, r - l);
        }
        return (d + 1) / 2;
    }
};
