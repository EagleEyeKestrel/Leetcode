//
//  main.cpp
//  一看就是双指针的题，注意这边要从后往前，不然会覆盖A的元素
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, now = A.size() - 1;
        while(i >= 0 && j >= 0) {
            if(A[i] <= B[j]) {
                A[now--] = B[j--];
            } else {
                A[now--] = A[i--];
            }
        }
        while(j >= 0) {
            A[now--] = B[j--];
        }
    }
};
