//
//  main.cpp
//  不用把全局和局部都求出来。只要证明不存在A[i + k] < A[i]，其中k >= 2
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if(n < 3) return true;
        int nowmax = A[0];
        for(int i = 2; i < n; i++) {
            if(A[i] < nowmax) return false;
            nowmax = max(nowmax, A[i - 1]);
        }
        return true;
    }
};
