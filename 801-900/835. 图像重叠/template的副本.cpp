//
//  main.cpp
//  两种思路
//  第一种是这里的做法，枚举两个方向的平移量
//  第二种，穷举两个矩阵的1，可以确定一个平移方向，在该平移方向上累加
//  复杂度一样的，但结果好像第二种快
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m = img1.size(), n = img1[0].size(), res = 0;
        for(int di = 1 - m; di <= m - 1; di++) {
            for(int dj = 1 - n; dj <= n - 1; dj++) {
                int tmp = 0;
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if(img1[i][j]) {
                            int ii = i + di, jj = j + dj;
                            if(ii >= 0 && ii < m && jj >= 0 && jj < n && img2[ii][jj]) {
                                tmp++;
                            }
                        }
                    }
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
