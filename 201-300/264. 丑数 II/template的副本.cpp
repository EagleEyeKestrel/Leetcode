//
//  main.cpp
//  丑数肯定可以由之前的丑数递推出来。那么在前面设上三个指针，每次取三个指针乘下来最小的那个
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = { 1 };
        int i1 = 0, i2 = 0, i3 = 0;
        for(int i = 1; i < n; i++) {
            int v1 = dp[i1] * 2, v2 = dp[i2] * 3, v3 = dp[i3] * 5;
            int v = min(min(v1, v2), v3);
            dp.push_back(v);
            if(v1 == v) i1++;
            if(v2 == v) i2++;
            if(v3 == v) i3++;
        }
        return dp[n - 1];
    }
};
