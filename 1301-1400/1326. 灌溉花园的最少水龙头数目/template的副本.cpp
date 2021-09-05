//
//  main.cpp
//  区间问题。等价于给n+1个区间，问最少多少个能够覆盖0-n
//  最优解是贪心。首先r[i]表示左端点为i的区间最右端是多少
//  然后对于0-i，维护左端点在0-l区间能达到的最大右端maxr。每次达到maxr之后res++，并更新新的maxr
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int r[n + 1];
        for (int i = 0; i <= n; i++) r[i] = i;
        for (int i = 0; i <= n; i++) {
            int L = max(0, i - ranges[i]), R = min(n, i + ranges[i]);
            r[L] = max(r[L], R);
        }
        int end = 0, res = 0, maxr = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n) break;
            maxr = max(maxr, r[i]);
            if (i == end) {
                if (maxr == end) {
                    return -1;
                }
                res++;
                end = maxr;
            }
        }
        return res;
    }
};
