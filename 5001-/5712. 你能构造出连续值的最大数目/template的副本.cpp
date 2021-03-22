//
//  main.cpp
//  对于一个范围[0,x]，一个新的硬币y 能够构造出[0,x] 并 [y,y+x]
//  排序后依次构造，如果y大于x+1，那么x+1无法构造了，直接退出
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int now = 0;
        for (int x: coins) {
            if (x > now + 1) break;
            now += x;
        }
        return now + 1;
    }
};
