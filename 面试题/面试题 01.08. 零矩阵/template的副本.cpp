//
//  main.cpp
//  如果不用暴力的话，用row和col记录一下某个行/列有没有0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int row[m], col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
