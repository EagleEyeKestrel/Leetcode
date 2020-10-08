//
//  main.cpp
//  dp。 dpa[i]表示前i个元素中，长度为L的子数组最大的和。
//  对于第i位，穷举第i位是L的末尾，或者M的末尾，或者都不是末尾，末尾在之前取到。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size(), res = 0;
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + A[i - 1];
        int dpa[n + 1], dpb[n + 1];
        memset(dpa, 0, sizeof(dpa));
        memset(dpb, 0, sizeof(dpb));
        for(int i = 1; i <= n; i++) {
            if(i >= L) dpa[i] = max(dpa[i - 1], s[i] - s[i - L]);
            if(i >= M) dpb[i] = max(dpb[i - 1], s[i] - s[i - M]);
            if(i >= L + M) res = max(res, max(s[i] - s[i - L] + dpb[i - L], s[i] - s[i - M] + dpa[i - M]));
        }
        return res;
    }
};
