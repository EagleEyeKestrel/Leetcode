//
//  main.cpp
//  一道没那么弱智的简单题，直接在A的个位加上K，然后进位。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size(), b = 0;
        A[n - 1] += K;
        for(int i = n - 1; i >= 0; i--) {
            if(A[i] >= 10) {
                if(i) A[i - 1] += A[i] / 10;
                else b = A[i] / 10;
                A[i] %= 10;
            }
        }
        while(b) {
            A.insert(A.begin(), b % 10);
            b /= 10;
        }
        return A;
    }
};
