//
//  main.cpp
//  先递增爬一段，再递减走一段
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;
        int i = 0;
        while(i + 1 < n && A[i + 1] > A[i]) i++;
        int j = i;
        while(j + 1 < n && A[j + 1] < A[j]) j++;
        return i && j == n - 1 && i != j;
    }
};
