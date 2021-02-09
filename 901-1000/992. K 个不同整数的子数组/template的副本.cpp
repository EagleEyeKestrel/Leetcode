//
//  main.cpp
//  假设子数组的右边界为r
//  可以维护子数组左边界的一个范围[l2,l1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), kinds1 = 0, kinds2 = 0, l1 = 0, l2 = 0, res = 0;
        int cnt1[20010] = { 0 }, cnt2[20010] = { 0 };
        for (int r = 0; r < n; r++) {
            cnt1[A[r]]++, cnt2[A[r]]++;
            if (cnt1[A[r]] == 1) kinds1++;
            if (cnt2[A[r]] == 1) kinds2++;
            while (l1 <= r && kinds1 >= K) {
                cnt1[A[l1]]--;
                if (cnt1[A[l1]] == 0) kinds1--;
                l1++;
            }
            while (l2 <= r && kinds2 > K) {
                cnt2[A[l2]]--;
                if (cnt2[A[l2]] == 0) kinds2--;
                l2++;
            }
            if (kinds1 != K - 1 || kinds2 != K) continue;
            res += l1 - l2;
        }
        return res;
    }
};
