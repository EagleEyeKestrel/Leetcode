//
//  main.cpp
//  思路是优先/2，带个记忆化
//  没想到速度这么快？因为一个数最多也就转化40来次
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<long long, int> mp;
    int integerReplacement(long long n) {
        if (n == 1) return 0;
        if (mp.count(n)) return mp[n];
        if (n % 2 == 0) return integerReplacement(n >> 1) + 1;
        int res = min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        mp[n] = res;
        return res;
    }
};
