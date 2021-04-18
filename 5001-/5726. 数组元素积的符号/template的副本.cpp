//
//  main.cpp
//  判断一下每个的符号即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (int num: nums) {
            if (num <= 0) res *= (-1);
            if (num == 0) return 0;
        }
        return res;
    }
};
