//
//  main.cpp
//  算出糖果差d 除以2，其实就是找A和B有没有差d的元素。排序双指针即可，当然也可以用cnt计数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int sumA = 0, sumB = 0;
        for(int num: A) sumA += num;
        for(int num: B) sumB += num;
        int d = (sumA - sumB) / 2, l = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int r = 0; r < n; r++) {
            while(l < m && A[l] < B[r] + d) l++;
            if(A[l] == B[r] + d) {
                return {A[l], B[r]};
            }
        }
        return {0, 0};
    }
};
