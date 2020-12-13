//
//  main.cpp
//  虽然简单，但我感觉这样解最快(更快的话可以提前break)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag1 = 0, flag2 = 0, n = A.size();
        for(int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) flag1 = 1;
            if (A[i] < A[i - 1]) flag2 = 1;
        }
        return flag1 + flag2 < 2;
    }
};
