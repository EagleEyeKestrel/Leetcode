//
//  main.cpp
//  比较简单的做法，O(mn2)
//  处理出每一行每个点的高度数组h，然后对以(i,j)为右下角的矩形，枚举左端点
//  左端点为k时，矩形的数量是这两个端点之间最小的h的高度
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        int h[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) h[j] = mat[i][j];
                else {
                    if (mat[i][j] == 0) h[j] = 0;
                    else h[j]++;
                }
                int minh = h[j];
                for (int k = j; k >= 0; k--) {
                    minh = min(minh, h[k]);
                    res += minh;
                }
            }
        }
        return res;
    }
};
