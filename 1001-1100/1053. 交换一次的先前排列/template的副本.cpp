//
//  main.cpp
//  首先找到从A末尾最长的递增(非递减序列)，假设是aL，L是最长序列，a是L前最后一个字符
//  如果a是空，那么直接返回（整个数列非递减
//  否则，找到L里小于a的最大字符和a交换（显然
//  如果有多个，取L中最左边的一个（a会被同样的数字替代，让a去尽量高的位置
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int i = n - 1;
        while (i >= 1 && A[i - 1] <= A[i]) i--;
        if (i == 0) return A;
        int val = A[i - 1], id = i - 1;
        i = n - 1;
        while (A[i] >= val) i--;
        while (i >= 1 && A[i - 1] == A[i]) i--;
        swap(A[i], A[id]);
        return A;
    }
};
