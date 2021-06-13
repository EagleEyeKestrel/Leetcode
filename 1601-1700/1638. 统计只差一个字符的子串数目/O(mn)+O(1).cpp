//
//  main.cpp
//  更好的解法，空间O(1)
//  对之前的解法空间优化，主要是学习遍历方法
//  因为每次都是由dp[i-1][j-1]更新dp[i][j]
//  所以每次根据i-j(delta)进行穷举
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), res = 0;
        for (int delta = 1 - n; delta <= m - 1; delta++) {
            int i = 1, j = 1;
            if (delta < 0) j = 1 - delta;
            if (delta > 0) i = 1 + delta;
            int gij = 0, dpij = 0, gij_pre = 0;
            while (i <= m && j <= n) {
                gij = s[i - 1] == t[j - 1] ? gij + 1 : 0;
                if (s[i - 1] != t[j - 1]) {
                    dpij = gij_pre + 1;
                }
                gij_pre = gij;
                res += dpij;
                i++, j++;
            }
        }
        return res;
    }
};
