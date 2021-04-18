//
//  main.cpp
//  关键是要想到，存在某个序列的gcd为x等价于，序列中所有x的倍数的最大公约数等于x
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int gcd(int a, int b) {
        return a % b ? gcd(b, a % b) : b;
    }
    int vis[200010];
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        memset(vis, 0, sizeof(vis));
        for (int num: nums) vis[num] = 1;
        for (int i = 1; i <= 200000; i++) {
            int tmp = -1;
            for (int j = i; j <= 200000; j += i) {
                if (vis[j]) {
                    if (tmp == -1) tmp = j;
                    else tmp = gcd(tmp, j);
                }
            }
            if (i == tmp) res++;
        }
        return res;
    }
};
