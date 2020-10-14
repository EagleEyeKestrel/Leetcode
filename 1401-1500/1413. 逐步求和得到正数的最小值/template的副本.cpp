//
//  main.cpp
//  求出最小的前缀和就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s = 0, minv = 0;
        for(int num: nums) {
            s += num;
            minv = min(minv, s);
        }
        return 1 - minv;
    }
};
