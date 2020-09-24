//
//  main.cpp
//  用 >=R的减去<L的即可
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int l1 = 0, l2 = 0, res1 = 0, res2 = 0;
        for(int r = 0; r < n; r++) {
            if(A[r] >= L) {
                l1 = r + 1;
            }
            if(A[r] > R) {
                l2 = r + 1;
            }
            res1 += r - l1 + 1;
            res2 += r - l2 + 1;
        }
        return res2 - res1;
    }
};
