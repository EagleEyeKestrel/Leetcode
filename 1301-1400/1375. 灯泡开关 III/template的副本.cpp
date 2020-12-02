//
//  main.cpp
//  排序，相加，当前和和light的前缀和相等时，说明当前刚好是这些数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), res = 0, tmp1 = 0, tmp2 = 0;
        for(int i = 1; i <= n; i++) {
            tmp1 += i;
            tmp2 += light[i - 1];
            if(tmp1 == tmp2) res++;
        }
        return res;
    }
};
