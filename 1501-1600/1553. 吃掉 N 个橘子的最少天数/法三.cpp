//
//  main.cpp
//  最好的解法，因为我们的目标很明确，就是要转化成倍数 然后用除法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<int, int> mp;
    int minDays(int n) {
        if (n <= 2) return n;
        if (n == 3) return 2;
        if (mp.count(n)) return mp[n];
        return mp[n] = min(minDays(n / 3) + n % 3 + 1, minDays(n / 2) + n % 2 + 1);
    }
};
