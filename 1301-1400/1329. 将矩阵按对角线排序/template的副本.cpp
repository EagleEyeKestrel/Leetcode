//
//  main.cpp
//  这里用的比较直观的解法，遍历每一个对角线，然后取出所有元素存在a里，排序，然后更新对角线
//  复杂度(n2logn)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int k = m - 1; k >= 1 - n; k--) {
            int starti = k >= 0 ? k : 0;
            int startj = k >= 0 ? 0 : -k;
            int a[110];
            int now = 0;
            for(int i = starti, j = startj; i < m && j < n; i++, j++) {
                a[now++] = mat[i][j];
            }
            sort(a, a + now);
            now = 0;
            for(int i = starti, j = startj; i < m && j < n; i++, j++) {
                mat[i][j] = a[now++];
            }
        }
        return mat;
    }
};
