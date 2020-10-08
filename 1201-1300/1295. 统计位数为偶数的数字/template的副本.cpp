//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int num: nums) {
            if(num >= 10 && num < 100 || num >= 1000 && num < 10000 || num >= 100000) res++;
        }
        return res;
    }
};
