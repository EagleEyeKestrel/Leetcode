//
//  main.cpp
//  不暴力的话，用row和col数组记录一下每一行/列出现1的次数，然后遍历看看是不是只出现了这一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] && row[i] == 1 && col[j] == 1) res++;
            }
        }
        return res;
    }
};
