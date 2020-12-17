//
//  main.cpp
//  其实就是找到最小的索引i使得 max(A[0],...,A[i]) <= min(A[i + 1]...A[n - 1])
//  把右边的用r预处理一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size(), nowmax = -1;
        int r[n];
        r[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) r[i] = min(r[i + 1], A[i]);
        for (int i = 0; i < n - 1; i++) {
            nowmax = max(nowmax, A[i]);
            if (nowmax <= r[i + 1]) return i + 1;
        }
        return 0;
    }
};
