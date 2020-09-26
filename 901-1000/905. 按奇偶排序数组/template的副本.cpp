//
//  main.cpp
//  空间是可以O(1)的，就从两头扫描然后交换就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r && A[l] % 2 == 0) l++;
            while(l < r && A[r] % 2 == 1) r--;
            swap(A[l], A[r]);
        }
        return A;
    }
};
