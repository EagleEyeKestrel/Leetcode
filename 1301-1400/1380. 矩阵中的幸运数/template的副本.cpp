//
//  main.cpp
//  计算鞍点。。
//  这里直接用O(n3)的暴力方法了，当然如果预处理一下r[i],c[i]记录每行的最小值和每列的最大值，就可以优化到O(n2)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int flag = 1;
                for(int k = 0; k < n; k++) {
                    if(matrix[i][j] > matrix[i][k]) {
                        flag = 0;
                        break;
                    }
                }
                if(!flag) continue;
                for(int k = 0; k < m; k++) {
                    if(matrix[i][j] < matrix[k][j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
