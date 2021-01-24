//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    inline int f(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size(), res = 0;
        int sum[n + 1];
        sum[0] = 0;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + f(s[i - 1]);
        for (int i = k; i <= n; i++) res = max(res, sum[i] - sum[i - k]);
        return res;
    }
};
