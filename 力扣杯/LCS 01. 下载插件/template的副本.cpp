//
//  main.cpp
//  下载速度可以倍增，那就穷举下载速度
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int leastMinutes(int n) {
        int res = n, now = 1, t = 0;
        while (now < n) {
            t++;
            now <<= 1;
            res = min(res, t + (n % now ? n / now + 1 : n / now));
        }
        return res;
    }
};
