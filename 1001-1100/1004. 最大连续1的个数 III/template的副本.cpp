//
//  main.cpp
//  滑动窗口，找到最长的窗口，使得内部0的个数不超过K
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), l = 1, res = 0;
        int presum[n + 1];
        presum[0] = 0;
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        for (int r = 1; r <= n; r++) {
            while (r - l + 1 - (presum[r] - presum[l - 1]) > K) l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
