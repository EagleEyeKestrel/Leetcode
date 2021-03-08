//
//  main.cpp
//  简单题，就是要注意int溢出
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int num: nums) sum += num;
        long long x = goal - sum;
        return abs(x) % limit ? abs(x) / limit + 1 : abs(x) / limit;
    }
};
