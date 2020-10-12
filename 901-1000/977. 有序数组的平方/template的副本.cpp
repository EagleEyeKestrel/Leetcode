//
//  main.cpp
//  思路很多
//  直接遍历push然后排序
//  或者插入到一个set里，然后直接依次取出
//  但是这些都是nlgn的。要O(n)的话还是要双指针
//  r初始化在>=0的最小数，l初始化在<0的最大数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = -1, r = n;
        while(l + 1 < n && A[l + 1] < 0) l++;
        while(r - 1 >= 0 && A[r - 1] >= 0) r--;
        vector<int> res;
        while(l >= 0 || r < n) {
            if(l >= 0 && r < n) {
                if(-A[l] > A[r]) {
                    res.push_back(A[r] * A[r]);
                    r++;
                } else {
                    res.push_back(A[l] * A[l]);
                    l--;
                }
            } else {
                if(l >= 0) {
                    res.push_back(A[l] * A[l]);
                    l--;
                }
                if(r < n) {
                    res.push_back(A[r] * A[r]);
                    r++;
                }
            }
        }
        return res;
    }
};
