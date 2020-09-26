//
//  main.cpp
//  第一次做的解法，前缀和，其实不难发现这个也可以做到空间O(1)
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        int zero[n + 1], one[n + 1];
        memset(zero, 0, sizeof(zero));
        memset(one, 0, sizeof(one));
        int cnt0 = 0, cnt1 = 0, res = INT_MAX;
        for(int i = 1; i <= n; i++) {
            if(S[i - 1] == '1') {
                one[i] = one[i - 1] + 1;
                zero[i] = zero[i - 1];
            } else {
                one[i] = one[i - 1];
                zero[i] = zero[i - 1] + 1;
            }
        }
        for(int i = 1; i <= n; i++) {
            res = min(res, (zero[n] - zero[i - 1]) + one[i - 1]);
        }
        return min(res, n - zero[n]);
    }
};
