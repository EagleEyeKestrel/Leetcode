//
//  main.cpp
//  前缀和s[i][j]表示从(1,1)到(i,j)的矩形前缀和，这样穷举一个正方形可以O(1)算出元素和
//  这里的复杂度是O(m*n*min(m,n))，当然更快的话可以二分k查找，这里显然满足可二分性质
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + s[i - 1][j] + mat[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 1; i <= m - k + 1; i++) {
                for (int j = 1; j <= n - k + 1; j++) {
                    int tmp = s[i + k - 1][j + k - 1] - s[i + k - 1][j - 1] - s[i - 1][j + k - 1] + s[i - 1][j - 1];
                    if (tmp <= threshold) return k;
                }
            }
        }
        return 0;
    }
};
