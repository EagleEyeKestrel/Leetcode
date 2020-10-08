//
//  main.cpp
//  swap[i]表示前i个元素，若交换A[i]B[i]，所需最小次数，noswap类似
//  讨论标准应该根据，要么是换不换都大于，要么是只有不换大于，要么是只有换了才大于
//  空间也可以优化到O(1)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int swap[n], noswap[n];
        swap[0] = 1;
        noswap[0] = 0;
        for(int i = 1; i < n; i++) {
            int a = A[i] > A[i - 1], b = B[i] > B[i - 1];
            int c = A[i] > B[i - 1], d = B[i] > A[i - 1];
            if(a && b && c && d) {
                swap[i] = min(swap[i - 1], noswap[i - 1]) + 1;
                noswap[i] = min(swap[i - 1], noswap[i - 1]);
            } else if(a && b) {
                swap[i] = swap[i - 1] + 1;
                noswap[i] = noswap[i - 1];
            } else {
                swap[i] = noswap[i - 1] + 1;
                noswap[i] = swap[i - 1];
            }
        }
        return min(swap[n - 1], noswap[n - 1]);
    }
};
