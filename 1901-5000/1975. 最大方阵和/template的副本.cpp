//
//  main.cpp
//  看上去挺难。实际上仔细想想，如果有偶数个负数，最后负号可以全部消掉
//  如果有奇数个负数，最后可以消的只剩下一个，我们让负号处于最小位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0, minv = INT_MAX;
        int m = matrix.size(), n = matrix[0].size(), cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minv = min(minv, (long long)abs(matrix[i][j]));
                res += abs(matrix[i][j]);
                if (matrix[i][j] < 0) cnt++;
            }
        }
        if (cnt & 1) return res - 2 * minv;
        return res;
    }
};
