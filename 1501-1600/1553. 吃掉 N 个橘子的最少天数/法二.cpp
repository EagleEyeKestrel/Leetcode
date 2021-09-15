//
//  main.cpp
//  第二次做的做法，法二
//  首先能除肯定除。关键就是-1的情况，这里让n%6!=0的时候都-1
//  乍一看复杂度还是O(n)，实际上应该是O(5log^2n)的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<int, int> mp;
    int minDays(int n) {
        if (n <= 2) return n;
        if (n == 3) return 2;
        if (mp.count(n)) return mp[n];
        int res = INT_MAX;
        if (n % 3 == 0) res = min(res, 1 + minDays(n / 3));
        if (n % 2 == 0) res = min(res, 1 + minDays(n / 2));
        if (n % 3 || n % 2) res = min(res, 1 + minDays(n - 1));
        mp[n] = res;
        return res;
    }
};
